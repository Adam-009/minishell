/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:40:55 by asaadi--          #+#    #+#             */
/*   Updated: 2025/02/12 13:48:18 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *text)
{
	int			i;
	int			o;
	long int	result;

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
