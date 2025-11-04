/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:06:43 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/22 11:30:24 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	size;

	i = 0;
	size = len;
	if (len > 2147483647)
		len = ft_strlen(s);
	if (len >= ft_strlen(s) - start)
		size = ft_strlen(s) - start;
	else if (start >= ft_strlen(s) || s == NULL)
	{
		size = 0;
		start = ft_strlen(s);
	}
	result = malloc(size + 1);
	if (result == NULL)
		return (NULL);
	while (s[start] && i < len)
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}

// int	main(void)
// {
// 	int	len = 18446744073709551615;
// 	int	start = 4294967295;
// 	char	text[] = "hola";
// 	printf("%s\n", ft_substr(text, start, len));
// }
