/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:03:09 by asaadi--          #+#    #+#             */
/*   Updated: 2025/05/23 15:57:47 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	c_quote(char *command)
{
	int	i;
	int	count_simple_quote;
	int	count_double_quote;

	i = 0;
	count_simple_quote = 0;
	count_double_quote = 0;
	while (command[i])
	{
		if (command[i] == '\'')
			count_simple_quote++;
		else if (command[i] == '\"')
			count_double_quote++;
		i++;
	}
	if ((count_double_quote % 2) != 0 || (count_simple_quote % 2) != 0)
		return (1);
	return (0);
}
