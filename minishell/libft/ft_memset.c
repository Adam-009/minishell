/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:44:13 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/15 11:44:39 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t count)
{
	char			*ptr2;
	unsigned char	c;
	size_t			i;

	i = 0;
	c = (unsigned char)value;
	ptr2 = ptr;
	while (i < count)
		ptr2[i++] = c;
	return (ptr);
}
