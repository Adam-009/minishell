/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:34:05 by letonnel          #+#    #+#             */
/*   Updated: 2025/10/27 17:24:33 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_split(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		i++;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

char	*find_path_cmd(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

void	free_cmd_list(t_cmd *head)
{
	t_cmd	*tmp;
	t_cmd	*next;

	while (head->prev)
		head = head->prev;
	tmp = head;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->infile != -1)
			close(tmp->infile);
		if (tmp->outfile != -1)
			close(tmp->outfile);
		free(tmp->cmd);
		free(tmp);
		tmp = next;
	}
}

void	end_pip(t_pipe *pipex)
{
	free(pipex->fd);
	free(pipex->pid);
}
