/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:48:41 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/05 17:43:36 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../minishell.h"

void	check_arg_num(char **cmd_args, t_minishell *mini)
{
	if (!cmd_args[1])
	{
		ft_putstr_fd("minishell: unset: not enough arguments\n", 2);
		mini->exit_status = 0;
	}
}

void	f_unset(t_minishell *mini, char **cmd_args)
{
	t_mini_env	*tmp;
	int			i;

	i = 1;
	check_arg_num(cmd_args, mini);
	while (cmd_args[i++])
	{
		tmp = mini->mini_env;
		while (tmp && ft_strcmp(tmp->name, cmd_args[i]) != 0)
			tmp = tmp->next;
		if (tmp)
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			else
				mini->mini_env = tmp->next;
			if (tmp->next)
			tmp->next->prev = tmp->prev;
			free(tmp->name);
			if (tmp->value)
				free(tmp->value);
			free(tmp);
		}
	}
	mini->exit_status = 0;
}
