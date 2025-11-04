/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:19:05 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/19 14:56:07 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
		ptr[i++] = '\0';
}

// int	main(void)
// {
// 	char buffer[5] = "njour";

// 	ft_bzero(&buffer[5], 1);
// 	printf("%s\n", buffer);
// 	return (0);
// }
