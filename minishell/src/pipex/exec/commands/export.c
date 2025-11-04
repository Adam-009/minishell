/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:47:13 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/04 17:07:21 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../minishell.h"

int	is_var_char_export(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_'
		|| (c >= '0' && c <= '9'));
}

void	ft_print_export(t_mini_env *mini_env)
{
	t_mini_env	*tmp;

	tmp = mini_env;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd("export ", 1);
			ft_putstr_fd(tmp->name, 1);
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putstr_fd("\"\n", 1);
		}
		else
		{
			ft_putstr_fd("export ", 1);
			ft_putstr_fd(tmp->name, 1);
			ft_putstr_fd("=\"\"\n", 1);
		}
		tmp = tmp->next;
	}
}

int	check_var(char *name)
{
	int	i;

	if (!name || !*name)
		return (1);
	if (!(ft_isalpha(name[0]) || name[0] == '_'))
		return (1);
	i = 1;
	while (name[i] && name[i] != '=')
	{
		if (!(ft_isalnum(name[i]) || name[i] == '_'))
			return (1);
		i++;
	}
	return (0);
}

void	modif_var(t_mini_env *mini_env, char *var, char *name)
{
	char	*value;

	value = get_value(var);
	while (mini_env && ft_strcmp(name, mini_env->name) != 0)
		mini_env = mini_env->next;
	if (!mini_env)
		return ;
	if (mini_env->value)
		free(mini_env->value);
	mini_env->value = value;
}

void	f_export(t_minishell *mini, char **cmd_args, t_pipe *pip)
{
	int		i;
	int		j;
	char	*name;
	char	*cmd;
	char	quote;

	i = 1;
	if (!cmd_args[1])
		return (ft_print_export(mini->mini_env), ft_exit(0, mini, 0, pip));
	while (cmd_args[i])
	{
		cmd = cmd_args[i];
		j = 0;
		quote = 0;
		while (cmd[j])
		{
		    if (cmd[j] == '"' || cmd[j] == '\'')
		    {
		        quote = cmd[j];
		        break; // on prend le premier quote trouvé
		    }
		    j++;
		}
		
		if (quote)
		{
		    i++;
		    while (cmd_args[i] && !ft_strchr(cmd_args[i], quote))
		    {
		        char *tmp = ft_strjoin(cmd, " "); // ajoute un espace
		        free(cmd);
		        cmd = ft_strjoin(tmp, cmd_args[i]);
		        free(tmp);
		        i++;
		    }
		    if (!cmd_args[i] || !ft_strchr(cmd_args[i], quote))
		    {
		        free(cmd);
		        return; // quote non fermé
		    }
		    // ajoute le dernier argument contenant la fermeture du quote
		    char *tmp = ft_strjoin(cmd, " ");
		    free(cmd);
		    cmd = ft_strjoin(tmp, cmd_args[i]);
		    free(tmp);
		}
		
		name = get_name(cmd);
		if (check_var(name) == 1)
		{
			free(name);
			return (ft_putstr_fd("minishell: export: not a valid identifier\n", 2),
				ft_exit(1, mini, 0, pip));
		}
		if (get_var(name, mini->mini_env) == NULL)
			addback_mini_env_list(&mini->mini_env,
				createnode_mini_env_list(cmd));
		else
			modif_var(mini->mini_env, cmd, name);
		free(name);
		i++;
	}
	return (ft_exit(0, mini, 0, pip));
}
