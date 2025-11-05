/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:46:20 by asaadi--          #+#    #+#             */
/*   Updated: 2025/05/28 11:41:13 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	parsing(char **command)
{
	char	**split;
	//int		i;

	//i = 0;
	split = ft_split(*command, ' ');
	if (c_quote(*command) == 1)
		return (ft_printf("Quote error\n"), 1);
	// if (c_redirection(split) == 1)
	// 	return (ft_printf("Redirection error\n"), 1);
	// if (c_pipe(*command) == 1)
	// 	return (ft_printf("Pipe error\n"), 1);
	free_array(split);
	return (0);
}
