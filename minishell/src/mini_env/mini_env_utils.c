/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:46:22 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/04 13:11:11 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

t_mini_env	*get_var(char *name, t_mini_env *mini_env)
{
	t_mini_env	*tmp;

	tmp = mini_env;
	while (tmp && ft_strcmp(tmp->name, name) != 0)
		tmp = tmp->next;
	return (tmp);
}

void	free_list_mini_env(t_mini_env *mini_env)
{
	t_mini_env	*tmp;

	while (mini_env)
	{
		tmp = mini_env->next;
		free(mini_env->name);
		free(mini_env->value);
		free(mini_env);
		mini_env = tmp;
	}
}

char	**minienv_lta(t_mini_env *mini_env)
{
	char		**array;
	t_mini_env	*tmp;
	int			count;
	int			i;
	char		*buf;

	count = 0;
	buf = NULL;
	tmp = mini_env;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	i = 0;
	tmp = mini_env;
	while (tmp)
	{
		buf = ft_strjoin(tmp->name, "=");
		array[i] = ft_strjoin(buf, tmp->value);
		i++;
		free(buf);
		tmp = tmp->next;
	}
	array[i] = NULL;
	return (array);
}

char	*get_name(const char *str)
{
	int		len;
	char	*equal;
	char	*result;

	if (!str)
		return (NULL);
	equal = ft_strchr(str, '=');
	if (equal)
		len = equal - str;
	else
		len = ft_strlen(str);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, len + 1);
	return (result);
}

char	*get_value(const char *var)
{
	char	*eq;
	char	*value;
	char	*new_val;

	eq = ft_strchr(var, '=');
	if (!eq)
		return (NULL);
	value = eq + 1;
	if ((*value == '"' && value[ft_strlen(value) - 1] == '"')
		|| (*value == '\'' && value[ft_strlen(value) - 1] == '\''))
	{
		new_val = ft_substr(value, 1, ft_strlen(value) - 2);
		return (new_val);
	}
	return (ft_strdup(value));
}
