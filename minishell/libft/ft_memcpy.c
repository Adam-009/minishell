/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:48:56 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/19 11:23:41 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (void *)src;
	ptr2 = (void *)dest;
	i = 0;
	if (ptr2 == NULL && ptr1 == NULL)
		return (0);
	while (i < n)
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src1[10] = "1234";
	char	dest1[10] = "testtest";

	char	src2[10] = "1234";
	char	dest2[10] = "testtest";

	printf("1 avant: %s\n", dest1);
	printf("2 avant: %s\n", dest2);
	ft_memcpy(dest1, src1, 4);
	memcpy(dest2, src2, 4);
	printf("1 apres: %s\n", dest1);
	printf("2 apres: %s\n", dest2);
}*/
