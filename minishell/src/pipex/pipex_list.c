/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:17:21 by asaadi--          #+#    #+#             */
/*   Updated: 2025/10/30 11:39:40 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*createnode_pipex(char *array)
{
	t_cmd	*newnode;

	newnode = malloc(sizeof(t_cmd));
	if (!newnode)
		return (NULL);
	ft_bzero(newnode, sizeof(t_cmd));
	if (array)
	{
		newnode->cmd = ft_strdup(array);
		if (!newnode->cmd)
		{
			free(newnode);
			return (NULL);
		}
	}
	else
		newnode->cmd = NULL;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->infile = -1;
	newnode->outfile = -1;
	return (newnode);
}

void	addback_pipex(t_cmd **head, t_cmd *newnode)
{
	t_cmd	*temp;

	if (!newnode)
		return ;
	if (!*head)
	{
		*head = newnode;
		newnode->prev = NULL;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = newnode;
	newnode->prev = temp;
}
