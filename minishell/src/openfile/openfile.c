/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:53:59 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/22 13:10:25 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	openfile(char *file, int oflag)
{
	int	fd;

	if (oflag & O_CREAT)
		fd = open(file, oflag, 0644);
	else
		fd = open(file, oflag);
	if (fd == -1)
	{
		error_msg_file("File error: ", file);
		return (-1);
	}
	return (fd);
}
