/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:35:58 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/18 17:03:08 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t size)
{
	size_t			i;
	unsigned char	*ptr2;
	unsigned char	*ptr1;

	ptr1 = ((unsigned char *)arr1);
	ptr2 = ((unsigned char *)arr2);
	i = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%i\n", memcmp("atoms\0\0\0\0", "atoms\0abc", 8));
	printf("%i\n", ft_memcmp("atoms\0\0\0\0", "atoms\0abc", 8));
}
*/