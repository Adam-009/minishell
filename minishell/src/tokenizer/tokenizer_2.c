/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:30:26 by asaadi--          #+#    #+#             */
/*   Updated: 2025/10/30 10:31:44 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../minishell.h"

int	skip_spaces(char *command, int i)
{
	while (command[i] == ' ' || command[i] == '\t' || command[i] == '\n')
		i++;
	return (i);
}
