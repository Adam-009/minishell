/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:52:48 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/14 11:26:47 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *text)
{
	int	i;
	int	o;
	int	result;

	result = 0;
	o = 1;
	i = 0;
	while ((text[i] >= 9 && text[i] <= 13) || text[i] == 32)
		i++;
	if (text[i] == 45 || text[i] == 43)
	{
		if (text[i] == 45)
			o = -1;
		i++;
	}
	while (text[i] >= 48 && text[i] <= 57)
	{
		result = result * 10 + (text[i] - '0');
		i++;
	}
	return (result * o);
}
