/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:05:43 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/18 17:43:36 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	c;

	j = 0;
	c = 0;
	ptr = (char *)src;
	i = 0;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	if (size == 0)
		return (0);
	while (dst[j])
	{
		j++;
		c++;
	}
	while (ptr[i] && j < size - 1)
		dst[j++] = ptr[i++];
	dst[j] = '\0';
	return (c + ft_strlen(src));
}
