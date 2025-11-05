/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:47:21 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/25 11:16:53 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)str;
	i = ft_strlen(ptr);
	while (i >= 0)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[19] = "ilf etait u\0ne fois";
// 	unsigned char	c = 'e';
// 	printf("%s\n", strrchr(str, c));
// 	printf("%s\n", ft_strrchr(str, c));
// }
