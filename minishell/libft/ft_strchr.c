/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:30:49 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/18 18:31:06 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if ((unsigned char)str[i] == (unsigned char)c)
		return ((char *)str + i);
	else
		return (NULL);
}
/*
int	main(void)
{
	char	str[] = "teste";
	char	c = 'e';
	printf("%s\n", strchr(str, c));
	printf("%s\n", ft_strchr(str, c));
}*/
