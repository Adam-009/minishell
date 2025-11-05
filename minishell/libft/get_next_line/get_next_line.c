/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:36:56 by asaadi--          #+#    #+#             */
/*   Updated: 2025/10/29 14:47:58 by letonnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_newbuffer(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen_gnl(buffer + i) + 1));
	if (!temp)
		return (NULL);
	i++;
	while (buffer[i])
		temp[j++] = buffer[i++];
	temp[j] = '\0';
	free(buffer);
	return (temp);
}

char	*ft_get_line(int fd, char *buffer)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (bytes != 0 && ft_strchr_gnl(buffer) == 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		buffer = ft_strjoin_gnl(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*ft_get_result(char *buffer)
{
	int		i;
	char	*result;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	result = ft_calloc_gnl(sizeof(char), (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		result[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		result[i] = buffer[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*result;

	if (fd == -42)
		free(buffer[fd]);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_get_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	result = ft_get_result(buffer[fd]);
	buffer[fd] = ft_newbuffer(buffer[fd]);
	return (result);
}
