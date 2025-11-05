/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:59:03 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/21 11:59:03 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (result == NULL)
		return (NULL);
	while (s[i])
	{
		result [i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
