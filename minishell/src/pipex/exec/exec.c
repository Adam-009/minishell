/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:57:27 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/05 17:43:47 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../minishell.h"

int	is_builtin(char *cmd_args)
{
	if (ft_strncmp(cmd_args, "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd_args, "env", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd_args, "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd_args, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd_args, "exit", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd_args, "export", 6) == 0)
		return (1);
	else if (ft_strncmp(cmd_args, "unset", 5) == 0)
		return (1);
	return (0);
}

int	exec(char *cmd, t_minishell *mini, t_pipe *pip)
{	
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (ft_strcmp(cmd_args[0], "pwd") == 0
		|| ft_strcmp(cmd_args[0], "pwd\n") == 0)
		f_pwd(mini->mini_env);
	else if (ft_strcmp(cmd_args[0], "env") == 0)
		f_env(mini->mini_env);
	else if (ft_strcmp(cmd_args[0], "echo") == 0)
		f_echo(mini->array, mini->exit_status);
	else if (ft_strcmp(cmd_args[0], "cd") == 0)
		f_cd(cmd_args, mini, pip);
	else if (ft_strcmp(cmd_args[0], "exit") == 0)
		f_exit(cmd_args, mini, 1, pip);
	else if (ft_strcmp(cmd_args[0], "export") == 0)
		f_export(mini, mini->array, pip);
	else if (ft_strcmp(cmd_args[0], "unset") == 0)
		f_unset(mini, cmd_args);
	free_array(cmd_args);
	return (0);
}
