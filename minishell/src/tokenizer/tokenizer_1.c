/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobriott <lobriott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:01:48 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/04 16:46:06 by lobriott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

int	check_op(char *command, int index)
{
	if (command[index] == '|')
		return (1);
	if (command[index] == '>')
	{
		if (command[index + 1] && command[index + 1] == '>')
			return (2);
		return (1);
	}
	if (command[index] == '<')
	{
		if (command[index + 1] && command[index + 1] == '<')
			return (2);
		return (1);
	}
	return (0);
}

int	count_arg(char *command)
{
	int		i;
	int		count;
	char	quote_char;

	i = 0;
	count = 0;
	while (command[i])
	{
		i = skip_spaces(command, i);
		if (!command[i])
			break ;
		if (check_op(command, i) != 0)
		{
			i += check_op(command, i);
			count++;
		}
		else
		{
			if (command[i] == '"' || command[i] == '\'')
			{
				quote_char = command[i++];
				while (command[i] && command[i] != quote_char)
					i++;
				if (command[i] == quote_char)
					i++;
				count++;
			}
			else
			{
				i = skip_word(command, i);
				count++;
			}
		}
	}
	return (count);
}

void	malloc_inside_array(char **array, char *command)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (command[i])
	{
		i = skip_spaces(command, i);
		if (!command[i])
			break ;
		if (command[i] == '"' || command[i] == '\'')
			len = malloc_quote(array, command, i, j);
		else if (check_op(command, i))
			len = malloc_operator(array, command, i, j);
		else
			len = malloc_word(array, command, i, j);
		if (len == -1)
			return (free_array(array));
		i += len;
		j++;
	}
}

int tokenizer(char *command, t_minishell *minishell)
{
	int	argc;
	int	i;

	argc = count_arg(command);
	if (argc == 0)
		return (-1);
	if (!ft_strncmp("\'\'", command, 3) || !ft_strncmp("\"\"", command, 3))
		return (printf("minishell: : command not found\n"), minishell->exit_status = 127, -1);
	minishell->array = malloc(sizeof(char *) * (argc + 1));
	if (!minishell->array)
		return(0);
	i = -1;
	while (++i <= argc)
		minishell->array[i] = NULL;
	malloc_inside_array(minishell->array, command);
	init_command_list(&minishell->command, minishell->array);
	return (0);
}
