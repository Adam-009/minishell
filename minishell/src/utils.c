/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobriott <lobriott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:28:05 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/04 16:36:10 by lobriott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **command)
{
	int	i;

	i = 0;
	if (!command)
		return ;
	if (command[i])
	{
		while (command[i])
			i++;
		while (i >= 0)
		{
			if (command[i] != NULL)
				free(command[i]);//
			i--;
		}
	}
	free(command);
}

void	free_list_cmd(t_Minishell *minishell)
{
	t_Command	*tmp;
	t_Command	*tmp2;

	tmp = minishell->command;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	free(tmp);
}

// void	free_array(char **array)
// {
// 	int	i;

// 	if (array == NULL)
// 		return ;
// 	i = 0;
// 	while (array[i])
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// }

// void	find_command(t_Minishell *minishell, int index)
// {
// 	if (ft_strcmp(minishell->command[index], "pwd") == 0)
// 		f_pwd();
// 	else if (ft_strcmp(minishell->command[index], "env") == 0)
// 		f_env(minishell->envp);
// 	else if (ft_strcmp(minishell->command[index], "echo") == 0)
// 	{
// 		if (ft_strcmp(minishell->command[index + 1], "-n") == 0)
// 			f_echo(minishell->command[index + 2], 1);
// 		else
// 			f_echo(minishell->command[index + 1], 0);
// 	}
// 	else if (ft_strcmp(minishell->command[index], "cd") == 0)
// 		f_cd(minishell->command[index + 1]);
// 	else if (ft_strcmp(minishell->command[index], "export") == 0)
// 		f_env(minishell->envp); /*a faire*/
// 	else if (ft_strcmp(minishell->command[index], "unset") == 0)
// 		f_env(minishell->envp); /*a faire*/
// }
