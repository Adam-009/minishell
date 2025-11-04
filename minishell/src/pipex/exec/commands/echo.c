/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:22:22 by asaadi--          #+#    #+#             */
/*   Updated: 2025/10/30 18:10:54 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../minishell.h"

int	is_var_char(char c)
{
	return ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9')
		|| c == '_');
}

static void	expand_var(const char *str, int *i, int exit_status)
{
	int		start;
	char	*var_name;
	char	*var_value;

	(*i)++;
	if (str[*i] == '?')
	{
		ft_printf("%d", exit_status);
		(*i)++;
		return ;
	}
	start = *i;
	while (str[*i] && is_var_char(str[*i]))
		(*i)++;
	if (*i > start)
	{
		var_name = ft_substr(str, start, *i - start);
		var_value = getenv(var_name);
		if (var_value)
			ft_printf("%s", var_value);
		free(var_name);
	}
	else
		ft_printf("$");
}

void	print_word(const char *str, int exit_status, int i)
{
	char	quote;

	while (str[i])
	{
		quote = 0;
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
			{
				if (quote == '"' && str[i] == '$')
					expand_var(str, &i, exit_status);
				else
					ft_printf("%c", str[i++]);
			}
			if (str[i] == quote)
				i++;
		}
		else if (str[i] == '$')
			expand_var(str, &i, exit_status);
		else
			ft_printf("%c", str[i++]);
	}
}

void	f_echo(char **cmd_args, int exit_status)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (cmd_args[1] && ft_strcmp(cmd_args[1], "-n") == 0)
	{
		newline = 0;
		i = 2;
	}
	while (cmd_args[i])
	{
		print_word(cmd_args[i], exit_status, 0);
		if (cmd_args[i + 1])
			ft_printf(" ");
		i++;
	}
	if (newline)
		ft_printf("\n");
}
