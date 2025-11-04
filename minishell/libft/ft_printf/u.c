/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:54:01 by asaadi--          #+#    #+#             */
/*   Updated: 2024/12/05 17:23:53 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned int nb);
static int	find_size(unsigned int n);

int	ft_u(unsigned int i)
{
	int	size;

	ft_putnbr(i);
	size = find_size(i);
	return (size);
}

static void	ft_putnbr(unsigned int nb)
{
	if (nb <= 9)
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

static int	find_size(unsigned int n)
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
