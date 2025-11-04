/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:03:48 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/18 12:13:47 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)src;
	copy = malloc((sizeof(char) * ft_strlen(ptr)) + 1);
	if (copy == NULL)
		return (NULL);
	while (ptr[i])
	{
		copy[i] = ptr[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
int	main(void)
{
	printf("%s\n", ft_strdup("lorem ipsum dolor sit amet"));
}*/
