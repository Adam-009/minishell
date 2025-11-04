/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:38:44 by asaadi--          #+#    #+#             */
/*   Updated: 2025/01/14 13:12:03 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int		find_param(char param, va_list arg);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	arg;

	i = 0;
	size = 0;
	if (str == NULL)
		return (-1);
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			size += find_param(str[i++ + 1], arg);
		else
		{
			write (1, &str[i], 1);
			size++;
		}
		i++;
	}
	va_end(arg);
	return (size);
}

static int	find_param(char param, va_list arg)
{
	if (param == 'c')
		return (ft_c(va_arg(arg, int)));
	else if (param == 'i' || param == 'd')
		return (ft_i(va_arg(arg, unsigned long)));
	else if (param == 'p')
		return (ft_p(va_arg(arg, void *)));
	else if (param == 's')
		return (ft_s(va_arg(arg, char *)));
	else if (param == 'u')
		return (ft_u(va_arg(arg, unsigned int)));
	else if (param == 'x' )
		return (ft_x(va_arg(arg, int), 0));
	else if (param == 'X')
		return (ft_x(va_arg(arg, int), 1));
	else
		write(1, "%", 1);
	return (1);
}
