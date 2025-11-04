/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comm_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:50:09 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/22 10:15:18 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	error_msg_comm(char *str1, char *str2)
{
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd("\n", 2);
}

void	free_everything(char *comm, char **path)
{
	free(comm);
	free_array(path);
}

char	*handle_direct_path(char *cmd)
{
	char	*path;

	path = check_full_path(cmd);
	if (!path)
	{
		error_msg_comm("Command error: ", cmd);
		exit(0);
	}
	return (path);
}
