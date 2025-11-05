/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:06:10 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/05 17:31:47 by asaadi--         ###   ########.fr       */
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
	while (1)
	{
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
			if (tokenizer(line, &minishell) == -1)
			{
				free(line);
				continue ;
			}
			exit_s = pipex(&minishell);
		}
		free(line);
		free_list_cmd(&minishell);
		free_array(minishell.array);
	}
	free_list_mini_env(minishell.mini_env);
	rl_clear_history();
	exit(exit_s);
}
