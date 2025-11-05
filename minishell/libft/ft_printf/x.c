/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:54:04 by asaadi--          #+#    #+#             */
/*   Updated: 2024/12/05 14:56:13 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned int nb, int value);
static char	ft_is_upper(int n, int value);

int	ft_x(int nb, int value)
{
	int				i;
	unsigned int	num;

	num = (unsigned int)nb;
	if (num == 0)
	{
		ft_c('0');
		return (1);
	}
	ft_putnbr(num, value);
	i = 0;
	while (num)
	{
		num /= 16;
		i++;
	}
	return (i);
}

static void	ft_putnbr(unsigned int nb, int value)
{
	if (nb >= 16)
	{
		ft_putnbr(nb / 16, value);
		ft_putnbr(nb % 16, value);
	}
	else
		ft_c(ft_is_upper(nb, value));
}

static char	ft_is_upper(int n, int value)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else
	{
		if (value == 0)
			return (n - 10 + 'a');
		else
			return (n - 10 + 'A');
	}
}
