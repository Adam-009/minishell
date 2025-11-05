/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:32:09 by asaadi--          #+#    #+#             */
/*   Updated: 2025/11/05 17:43:44 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "./../../../minishell.h"

typedef struct s_mini_env	t_mini_env;
typedef struct s_pipe		t_pipe;
typedef struct s_Minishell	t_minishell;

void	f_pwd(t_mini_env *mini_env);
void	f_env(t_mini_env *mini_env);
void	f_echo(char **cmd_args, int exit_status);
void	f_cd(char **args, t_minishell *mini, t_pipe *pip);
void	ft_exit(int code, t_minishell *mini, int exit_now, t_pipe *pip);
void	f_exit(char **cmd_args, t_minishell *mini, int exit_now, t_pipe *pip);
void	f_unset(t_minishell *mini, char **cmd_args);
void	f_export(t_minishell *mini, char **cmd_args, t_pipe *pip);
char	*get_full_argument(char **cmd_args, int *i);
int		handle_export_arg(t_minishell *mini, char *cmd);
int		check_var(char *name);
void	modif_var(t_mini_env *mini_env, char *var, char *name);

#endif