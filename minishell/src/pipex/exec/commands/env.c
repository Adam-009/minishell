/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:53:57 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/04 18:32:59 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../minishell.h"

void	f_env(t_mini_env *mini_env)
{
	t_mini_env	*tmp;

	tmp = mini_env;
	while (tmp)
	{
		if (tmp->value)
			ft_printf("%s=%s\n", tmp->name, tmp->value);
		else
			ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
}
