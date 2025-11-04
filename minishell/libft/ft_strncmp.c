/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:31:43 by asaadi--          #+#    #+#             */
/*   Updated: 2025/03/19 11:43:13 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t l)
{
	size_t	i;

	i = 0;
	if (l == 0)
		return (0);
	while ((((unsigned char)str1[i]) && ((unsigned char)str2[i]))
		&& ((unsigned char)str1[i]) == ((unsigned char)str2[i]) && (i < l - 1))
		i++;
	if ((((unsigned char)str1[i]) - ((unsigned char)str2[i])) < 0)
		return (-1);
	else if ((((unsigned char)str1[i]) - ((unsigned char)str2[i])) > 0)
		return (1);
	return (((unsigned char)str1[i]) - ((unsigned char)str2[i]));
}
/*
int	main(void)
{
	printf("%i\n", strncmp("test\200", "test\0", 6));
	printf("%i\n", ft_strncmp("test\200", "test\0", 6));
}*/
