/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:54:02 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/04 12:03:12 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

t_mini_env	*createnode_mini_env_list(char *array)
{
	t_mini_env	*newnode;
	char		*tmp;
	int			shlvl;

	newnode = (t_mini_env *)malloc(sizeof(t_mini_env));
	if (!newnode)
		return (NULL);
	newnode->name = get_name(array);
	if (ft_strcmp(newnode->name, "SHLVL") == 0)
	{
		tmp = get_value(array);
		shlvl = ft_atoi(tmp) + 1;
		free(tmp);
		newnode->value = ft_itoa(shlvl);
	}
	else
		newnode->value = get_value(array);
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	addback_mini_env_list(t_mini_env **head, t_mini_env *newnode)
{
	t_mini_env	*temp;

	if (!newnode)
		return ;
	if (!*head)
	{
		*head = newnode;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = newnode;
	newnode->prev = temp;
}

void	init_mini_env_list(t_mini_env **command, char **array)
{
	int			i;
	t_mini_env	*temp;

	i = 0;
	while (array[i])
	{
		temp = createnode_mini_env_list(array[i++]);
		if (!temp)
			return ;
		addback_mini_env_list(command, temp);
	}
}
