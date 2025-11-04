/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobriott <lobriott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:47:26 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/04 15:51:34 by lobriott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../minishell.h"

int	array_length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	check_overflow(char *status)
{
	long long	num;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	while ((status[i] >= 9 && status[i] <= 13) || status[i] == ' ')
		i++;
	if (status[i] == '-' || status[i] == '+')
	{
		if (status[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while (status[i] >= '0' && status[i] <= '9')
	{
		if (num > (LLONG_MAX - (status[i] - '0')) / 10 && sign == 1)
			return (1);
		if (-num < (LLONG_MIN + (status[i] - '0')) / 10 && sign == -1)
			return (1);
		num = num * 10 + (status[i] - '0');
		i++;
	}
	return (0);
}

int	ft_check_num(char *text)
{
	int	i;
	int	o;
	int	result;

	result = 0;
	o = 1;
	i = 0;
	while ((text[i] >= 9 && text[i] <= 13) || text[i] == 32)
		i++;
	if (text[i] == '"')
		i++;
	if (text[i] == 45 || text[i] == 43)
	{
		if (text[i] == 45)
			o = -1;
		i++;
	}
	if (text[i] == '"')
		i++;
	while (text[i] >= 48 && text[i] <= 57)
	{
		result = result * 10 + (text[i] - '0');
		i++;
	}
	return (result * o);
}

void	f_exit(char **cmd_args, t_minishell *mini, int exit_now, t_pipe *pip)
{
	int	status;

	if (ft_isdigit(cmd_args[1][0]) == 0 && cmd_args[1][0] != '"'
		&& cmd_args[1][0] != '+' && cmd_args[1][0] != '-')
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		exit(2);
	}
	if (check_overflow(cmd_args[1]) == 1)
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		exit(2);
	}	
	status = ft_check_num(cmd_args[1]);
	if (array_length(cmd_args) > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		status = 1;
	}
	mini->exit_status = status;
	if (exit_now == 1)
	{
		free_array(cmd_args);//
		free_array(mini->array);
		free_list_mini_env(mini->mini_env);
		free_list_cmd(mini);
		free_cmd_list(pip->head_cmd);
		free(pip->fd);//
		free(pip->pid);
		init_fds(mini, 1);
		exit(status);
	}
}

void	ft_exit(int code, t_minishell *mini, int exit_now, t_pipe *pip)
{
	char	*args[3];

	args[0] = "exit";
	args[1] = ft_itoa(code);
	args[2] = NULL;
	f_exit(args, mini, exit_now, pip);//
	free(args[1]);
}
