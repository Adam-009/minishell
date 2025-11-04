/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:35:38 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/04 17:35:59 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../minishell.h"

void	ft_exit(int code, t_minishell *mini, int exit_now, t_pipe *pip)
{
	char	*args[3];

	args[0] = "exit";
	args[1] = ft_itoa(code);
	args[2] = NULL;
	f_exit(args, mini, exit_now, pip);
	free(args[1]);
}
