/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:37:00 by asaadi--          #+#    #+#             */
/*   Updated: 2025/02/05 14:18:09 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero_gnl(void *s, size_t n);

int	ft_strchr_gnl(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_gnl(const char *text)
{
	int	i;

	i = 0;
	while (text[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc_gnl(sizeof(char), 1);
	result = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!result)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

void	*ft_calloc_gnl(size_t c, size_t s)
{
	void	*ptr;

	ptr = malloc(s * c);
	if (ptr == NULL)
		return (0);
	ft_bzero_gnl(ptr, c * s);
	return (ptr);
}

void	ft_bzero_gnl(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
		ptr[i++] = '\0';
}
