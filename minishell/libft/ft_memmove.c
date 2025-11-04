/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:00:35 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/26 17:51:44 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	i = 0;
	ptr1 = (char *)dest;
	ptr2 = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest)
	{
		while (size-- > i)
			ptr1[size] = ptr2[size];
	}
	else
	{
		while (i < size)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	return (dest);
}
