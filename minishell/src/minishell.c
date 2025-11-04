/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:06:10 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/03 13:17:52 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	g_signal;

void	print_list(t_Minishell *minishell)
{
	t_Command	*tmp;

	tmp = minishell->command;
	while (tmp)
	{
		printf("%s: %i\n", tmp->cmd, tmp->token);
		tmp = tmp->next;
	}
}

void	init_fds(t_Minishell *mini, int i)
{
	if (i == 0)
	{
		mini->fd[0] = dup(STDIN_FILENO);
		mini->fd[1] = dup(STDOUT_FILENO);
	}
	if (i == 1)
	{
		close(mini->fd[0]);
		close(mini->fd[1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_Minishell	minishell;
	char		*line;
	int			exit_s;

	minishell.mini_env = NULL;
	init_mini_env_list(&minishell.mini_env, envp);
	minishell.array = NULL;
	minishell.exit_status = 0;
	if (argc != 1 || argv[1])
		return (0);
	init_fds(&minishell, 0);
	while (1)
	{
		dup2(minishell.fd[0], STDIN_FILENO);
		dup2(minishell.fd[1], STDOUT_FILENO);
		minishell.command = NULL;
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)
			&& isatty(STDERR_FILENO))
			line = readline("minishell$ ");
		else
			line = get_next_line(0);
		exit_s = minishell.exit_status;
		if (!line || ft_strcmp(line, "exit") == 0)
		{
			exit_s = minishell.exit_status;
			free(line);
			free_list_cmd(&minishell);
			break ;
		}
		else if (line)
		{
			history(line);
			tokenizer(line, &minishell);
			exit_s = pipex(&minishell);
		}
		free(line);
		free_list_cmd(&minishell);
		free_array(minishell.array);
	}
	free_list_mini_env(minishell.mini_env);
	rl_clear_history();
	init_fds(&minishell, 1);
	exit(exit_s);
}
