/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:32:53 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/13 17:13:18 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	char	c;
	c = ')';
	printf("%i\n", ft_isalnum(c));
}*/
