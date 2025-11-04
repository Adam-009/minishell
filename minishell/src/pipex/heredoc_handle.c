/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:45:28 by letonnel          #+#    #+#             */
/*   Updated: 2025/10/30 11:41:07 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "pipex.h"

void	get_here(int *fd, char *delim)
{
	char	*line;

	line = NULL;
	close(fd[0]);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (ft_strncmp(line, delim, ft_strlen(delim)) == 0)
		{
			free(line);
			get_next_line(-42);
			close(fd[1]);
			exit(0);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
}

void	heredoc(char *delim)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		get_here(fd, delim);
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
}
