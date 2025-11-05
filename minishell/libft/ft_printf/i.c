/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:53:50 by asaadi--          #+#    #+#             */
/*   Updated: 2024/12/04 14:30:59 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int nb);
static int	find_size(int n);

int	ft_i(int i)
{
	int	size;

	ft_putnbr(i);
	size = find_size(i);
	return (size);
}

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_c('-');
	}
	if (nb <= 9 && nb >= 0)
	{
		nb = nb + '0';
		ft_c(nb);
	}
	else
	{
		ft_putnbr (nb / 10);
		ft_putnbr (nb % 10);
	}
}

static int	find_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}
