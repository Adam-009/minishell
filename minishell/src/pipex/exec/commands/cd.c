/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:35:42 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/04 18:34:41 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../minishell.h"

void	change_pwd(t_minishell *mini, char *new_pwd, char *old_pwd)
{
	t_mini_env	*tmp;

	tmp = mini->mini_env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PWD"))
			old_pwd = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	tmp = mini->mini_env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "PWD") == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(new_pwd);
		}
		else if (ft_strcmp(tmp->name, "OLDPWD") == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(old_pwd);
		}
		tmp = tmp->next;
	}
	free(old_pwd);
}

void	var_home(t_minishell *mini, t_pipe *pip)
{
	char	*var;

	var = getenv("HOME");
	if (!var || chdir(var) != 0)
	{
		perror("minishell: cd");
		ft_exit(1, mini, 0, pip);
	}
}

void	too_much(t_minishell *mini, t_pipe *pip)
{
	ft_putstr_fd("minishell: cd: too many arguments\n", 2);
	ft_exit(1, mini, 0, pip);
}

void	not_found(t_minishell *mini, t_pipe *pip)
{
	perror("minishell: cd");
	ft_exit(1, mini, 0, pip);
}

void	f_cd(char **args, t_minishell *mini, t_pipe *pip)
{
	char	*var;
	char	*cwd;

	mini->exit_status = 0;
	// ft_printf("%s\n", args[1]);
	if (!args[1])
		return (var_home(mini, pip));
	if (args[2])
		return (too_much(mini, pip));
	if (args[1][0] == '$')
	{
		var = get_var(args[1] + 1, mini->mini_env)->value;
		if (!var || chdir(var) != 0)
			return (free(var), not_found(mini, pip));
		var = getcwd(NULL, 0);
		change_pwd(mini, var, NULL);
		free(var);
		return (ft_exit(0, mini, 0, pip));
	}
	if (chdir(args[1]) != 0)
		return (not_found(mini, pip));
	ft_printf("in\n");
	cwd = getcwd(NULL, 0);
	change_pwd(mini, cwd, NULL);
	ft_printf("%s\n", cwd);
	free(cwd);
	ft_exit(0, mini, 0, pip);
}
