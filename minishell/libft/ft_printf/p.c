/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:53:54 by asaadi--          #+#    #+#             */
/*   Updated: 2024/12/05 15:56:09 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(unsigned long long int nb);

int	ft_p(void *ptr)
{
	int						i;
	unsigned long long int	num;

	num = (unsigned long long int)ptr;
	i = 2;
	if (!num || !ptr)
	{
		ft_s("(nil)");
		return (5);
	}
	ft_s("0x");
	i += ft_putnbr(num);
	return (i);
}

static int	ft_putnbr(unsigned long long int nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_putnbr(nb / 16);
	}
	if (nb % 16 < 10)
	{
		ft_c(nb % 16 + '0');
		count++;
	}
	else
	{
		ft_c(nb % 16 - 10 + 'a');
		count++;
	}
	return (count);
}
