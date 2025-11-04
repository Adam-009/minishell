/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:58:36 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/15 18:38:57 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t c, size_t s)
{
	void	*ptr;

	ptr = malloc(s * c);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, c * s);
	return (ptr);
}
/*
int	main(void)
{
	printf("%i\n", ft_calloc(2, 3));
}*/
