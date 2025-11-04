/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:39:46 by asaadi--          #+#    #+#             */
/*   Updated: 2025/10/30 10:40:36 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	skip_word(char *cmd, int i)
{
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t' && check_op(cmd, i) == 0)
		i++;
	return (i);
}

int	malloc_operator(char **array, char *cmd, int i, int j)
{
	int	len;
	int	k;

	len = check_op(cmd, i);
	array[j] = malloc(sizeof(char) * (len + 1));
	if (!array[j])
		return (-1);
	k = 0;
	while (k < len)
	{
		array[j][k] = cmd[i + k];
		k++;
	}
	array[j][len] = '\0';
	return (len);
}

int	malloc_word(char **array, char *cmd, int i, int j)
{
	int	start;
	int	len;
	int	k;

	start = i;
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t' && check_op(cmd, i) == 0)
		i++;
	len = i - start;
	array[j] = malloc(sizeof(char) * (len + 1));
	if (!array[j])
		return (-1);
	k = 0;
	while (k < len)
	{
		array[j][k] = cmd[start + k];
		k++;
	}
	array[j][len] = '\0';
	return (len);
}

int	malloc_quote(char **array, char *cmd, int start, int j)
{
	char	quote_char;
	int		len;
	int		k;

	quote_char = cmd[start];
	len = 1;
	while (cmd[start + len] && cmd[start + len] != quote_char)
		len++;
	if (cmd[start + len] != quote_char)
		return (-1);
	len++;
	array[j] = malloc(sizeof(char) * (len + 1));
	if (!array[j])
		return (-1);
	k = 0;
	while (k < len)
	{
		array[j][k] = cmd[start + k];
		k++;
	}
	array[j][len] = '\0';
	return (len);
}
