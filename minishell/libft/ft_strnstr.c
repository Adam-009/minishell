/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:59:35 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/15 16:20:58 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	int		x;
	size_t	v;

	i = 0;
	if (!(char) s2[0])
		return ((char *)&s1[0]);
	while ((char)s1[i] && i < len)
	{
		x = 0;
		if ((char)s1[i] == (char)s2[x])
		{
			v = i;
			while ((char)s1[v] == (char)s2[x] && (char)s1[v] != '\0' && v < len)
			{
				v++;
				x++;
			}
		}
		if ((char)s2[x] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "lorem ipsum dolor sit amet";
	char	s2[] = "dolor";
	int		len;

	len = 15;
	printf("%s\n", ft_strnstr(s1, s2, len));
}*/