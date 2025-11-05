/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:34:02 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/18 19:08:28 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%p\n", ft_memchr("qwertyuiop", 'o', 10));
	printf("%p\n", memchr("qwertyuiop", 'o', 10));
}*/
