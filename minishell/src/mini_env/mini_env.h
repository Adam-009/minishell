/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:00:13 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/04 12:52:19 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_ENV_H
# define MINI_ENV_H

# include "./../minishell.h"

char		*get_value(const char *str);
char		*get_name(const char *str);
char		**minienv_lta(t_mini_env *mini_env);
void		free_list_mini_env(t_mini_env *mini_env);
t_mini_env	*get_var(char *name, t_mini_env *mini_env);
void		addback_mini_env_list(t_mini_env **head, t_mini_env *newnode);
t_mini_env	*createnode_mini_env_list(char *array);

#endif