/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:31:53 by asaadi--          #+#    #+#             */
/*   Updated: 2025/10/30 17:43:15 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../minishell.h"

void	f_pwd(t_mini_env *mini_env)
{
	t_mini_env	*tmp;

	tmp = mini_env;
	while (tmp && ft_strcmp("PWD", tmp->name) != 0)
		tmp = tmp->next;
	if (tmp && tmp->value)
		ft_printf("%s\n", tmp->value);
}
