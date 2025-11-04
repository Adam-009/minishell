/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:47:16 by letonnel          #+#    #+#             */
/*   Updated: 2025/11/04 14:17:40 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_join(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = -1;
	j = 0;
	if (result == NULL)
		return (NULL);
	while (s1[++i])
		result[i] = s1[i];
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	free(s1);
	return (result);
}

void	pre_exec(t_command *cmd, t_pipe *pipex)
{
	t_cmd	*head;
	char	*line;
	t_cmd	*node;

	head = NULL;
	while (cmd)
	{
		if ((cmd->token == TEXT && !cmd->prev)
			|| (cmd->token == TEXT && is_redir(cmd->prev->token) == 0))
		{
			line = ft_strdup(cmd->cmd);
			while (cmd->next && cmd->next->token == TEXT)
			{
				line = ft_join(line, " ");
				line = ft_join(line, cmd->next->cmd);
				cmd = cmd->next;
			}
			node = createnode_pipex(line);
			free(line);
			addback_pipex(&head, node);
		}
		cmd = cmd->next;
	}
	pipex->head_cmd = head;
}

void	dup_redir(t_cmd *cmd, t_pipe *pip)
{
	if (pip->i > 0 && cmd->infile == -1)
		dup2(pip->fd[2 * pip->i - 2], STDIN_FILENO);
	if (cmd->next && cmd->outfile == -1)
		dup2(pip->fd[2 * pip->i + 1], STDOUT_FILENO);
	if (cmd->infile != -1)
		dup2(cmd->infile, STDIN_FILENO);
	if (cmd->outfile != -1)
		dup2(cmd->outfile, STDOUT_FILENO);
}

void	child_process(t_pipe *pip, t_cmd *cmd, t_Minishell *mini)
{
	/*if (pip->i == 0)*/
	/*{*/
	/*	dup2(cmd->infile, STDIN_FILENO);*/
	/*	if (cmd->outfile != -1)*/
	/*		dup2(cmd->outfile, STDOUT_FILENO);*/
	/*	if (cmd->infile != -1)*/
	/*		if (dup2(cmd->infile, STDIN_FILENO) == -1)*/
	/*			perror("dup2 infile error");*/
	/*	if (cmd->next)*/
	/*		dup2(pip->fd[2 * pip->i + 1], STDOUT_FILENO);*/
	/*}*/
	/*else if (pip->i > 0 && cmd->next)*/
	/*{*/
	/*	dup2(pip->fd[2 * pip->i - 2], STDIN_FILENO);*/
	/*	dup2(pip->fd[2 * pip->i + 1], STDOUT_FILENO);*/
	/*	if (cmd->outfile != -1)*/
	/*		dup2(cmd->outfile, STDOUT_FILENO);*/
	/*	if (cmd->infile != -1)*/
	/*		dup2(cmd->infile, STDIN_FILENO);*/
	/*}*/
	/*else if (pip->i > 0 && !cmd->next)*/
	/*{*/
	/*	dup2(pip->fd[2 * pip->i - 2], STDIN_FILENO);*/
	/*	if (cmd->outfile != -1)*/
	/*		dup2(cmd->outfile, STDOUT_FILENO);*/
	/*	if (cmd->infile != -1)*/
	/*		dup2(cmd->infile, STDIN_FILENO);*/
	/*}*/
	if (pip->i > 0 && cmd->infile == -1)
		dup2(pip->fd[2 * pip->i - 2], STDIN_FILENO);
	if (cmd->next && cmd->outfile == -1)
		dup2(pip->fd[2 * pip->i + 1], STDOUT_FILENO);
	if (cmd->infile != -1)
		dup2(cmd->infile, STDIN_FILENO);
	if (cmd->outfile != -1)
		dup2(cmd->outfile, STDOUT_FILENO);
	/*dup_redir(cmd, pip);*/
	close(mini->fd[0]);
	close(mini->fd[1]);
	close_pipes(pip);
	if (is_builtin(cmd->cmd) == 1 && ft_strncmp(cmd->cmd, "cd", 2) != 0
		&& cmd->next)
		exec(cmd->cmd, mini, pip);
	else if (is_builtin(cmd->cmd) == 0)
		proc(cmd->cmd, minienv_lta(mini->mini_env), *pip, mini);
}

void	parent_process(t_pipe *pip, t_cmd *cmd, t_Minishell *mini)
{
	pip->pid[pip->i] = fork();
	if (pip->pid[pip->i] == 0)
		child_process(pip, cmd, mini);
	else if (is_builtin(cmd->cmd) == 1 && ft_strncmp(cmd->cmd, "cd", 2) == 0)
		exec(cmd->cmd, mini, pip);
	else if (is_builtin(cmd->cmd) == 1 && cmd->next == NULL)
		exec(cmd->cmd, mini, pip);
}

void	start_exec(t_pipe *pipex, t_minishell *minishell)
{
	t_cmd	*tmp;

	pipex->i = 0;
	tmp = pipex->head_cmd;
	while (tmp)
	{
		pipex->head_cmd = tmp;
		parent_process(pipex, tmp, minishell);
		tmp = tmp->next;
		pipex->i++;
	}
}
