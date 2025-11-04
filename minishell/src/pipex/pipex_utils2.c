/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:41:57 by letonnel          #+#    #+#             */
/*   Updated: 2025/10/30 11:39:45 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_error(int code, char *arg)
{
	if (code == 1)
		ft_putstr_fd("permission denied: ", 2);
	else if (code == 2)
		ft_putstr_fd("command not found: ", 2);
	else if (code == 3)
		ft_putstr_fd("syntax error near unexpected token `|'", 2);
	else if (code == 4)
		ft_putstr_fd("syntax error near unexpected token `newline'", 2);
	(void)arg;
	ft_putstr_fd("\n", 2);
}

char	*get_cmd_path(char *cmd, char **env, t_pipe *pip)
{
	char	*path_cmd;
	char	**split_path;
	char	**cmd_arg;
	char	*temp;
	int		i;

	i = -1;
	path_cmd = find_path_cmd(env);
	split_path = ft_split(path_cmd + 5, ':');
	cmd_arg = ft_split(cmd, ' ');
	while (split_path[++i] && cmd_arg[0])
	{
		temp = ft_strjoin(split_path[i], "/");
		path_cmd = ft_strjoin(temp, cmd_arg[0]);
		free(temp);
		if (access(path_cmd, F_OK) == 0)
			pip->found = 1;
		if (access(path_cmd, F_OK | X_OK) == 0)
			break ;
		if (split_path[i + 1])
			free(path_cmd);
	}
	free_split(split_path);
	free_split(cmd_arg);
	return (path_cmd);
}

void	init_pipe(int ac, t_pipe *pipex)
{
	pipex->exit = 0;
	pipex->cmds = ac;
	pipex->fd = ft_calloc(sizeof(int), (pipex->cmds) * 2);
	pipex->pid = ft_calloc(sizeof(int), pipex->cmds);
	pipex->i = -1;
}

int	get_exit_status(t_pipe pipex)
{
	int	status;
	int	i;

	i = 0;
	status = 0;
	while (waitpid(pipex.pid[i], &status, 0) > 0 && i < pipex.cmds - 1)
		i++;
	return (WEXITSTATUS(status));
}
