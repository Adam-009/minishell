/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:54:17 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/22 13:12:00 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENFILE_H
# define OPENFILE_H

# include "./../minishell.h"

void	error_msg_file(char *str1, char *str2);
int		openfile(char *file, int oflag);

#endif