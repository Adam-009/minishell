/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:50:35 by letonnel          #+#    #+#             */
/*   Updated: 2025/11/04 16:59:43 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "pipex.h"

int	is_redir(t_token token)
{
	if (token == L_REDIR)
		return (1);
	if (token == R_REDIR)
		return (2);
	if (token == DL_REDIR)
		return (3);
	if (token == DR_REDIR)
		return (4);
	return (0);
}

int	try_open(char *file, int i)
{
	int	fd;

	fd = -1;
	if (i == 0)
		fd = open(file, O_RDONLY);
	if (i == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		print_error(1, file);
	return (fd);
}

void	check_redir(t_command *cmd, t_pipe *pipex)
{
	t_cmd	*tmp;

	tmp = pipex->head_cmd;
	while (cmd && cmd->next)
	{
		if (cmd->token == PIPE)
			tmp = tmp->next;
		if (is_redir(cmd->token) == 1)
			tmp->infile = try_open(cmd->next->cmd, 0);
		else if (is_redir(cmd->token) == 2)
			tmp->outfile = try_open(cmd->next->cmd, 1);
		else if (is_redir(cmd->token) == 3)
			heredoc(cmd->next->cmd);
		else if (is_redir(cmd->token) == 4)
			tmp->outfile = try_open(cmd->next->cmd, 2);
		cmd = cmd->next;
	}
}
