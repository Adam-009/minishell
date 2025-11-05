/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:08:22 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/19 11:23:45 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;
	char			*ptr;

	ptr = (char *)src;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size -1 && ptr[i])
	{
		dst[i] = ptr[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{

	char *dest;
	
	dest = malloc(20 * sizeof(char));
	printf("%zu\n", ft_strlcpy(dest, "lorem", 15));
}*/