/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:50:47 by letonnel          #+#    #+#             */
/*   Updated: 2025/11/03 11:43:20 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include "./../minishell.h"

typedef struct s_Minishell	t_minishell;
typedef struct s_Command	t_command;
typedef enum e_token		t_token;

typedef struct s_cmd
{
	char			*cmd;
	int				infile;
	int				outfile;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_pipe
{
	char		**split_path;
	char		**cmd;
	int			i;
	int			exit;
	int			cmds;
	int			*fd;
	pid_t		*pid;
	int			found;
	int			here;
	t_cmd		*head_cmd;
}	t_pipe;

void		free_split(char **tab);
char		*find_path_cmd(char **env);
void		close_pipes(t_pipe *pipex);
void		create_pipes(t_pipe *pipex);
void		end_pip(t_pipe *pipex);
char		*get_cmd_path(char *cmd, char **env, t_pipe *pip);
void		init_pipe(int ac, t_pipe *pipex);
int			get_exit_status(t_pipe pipex);
void		print_error(int code, char *arg);
char		**parse_line(int *ac, char *line, t_pipe *pip);
void		addback_pipex(t_cmd **head, t_cmd *newnode);
t_cmd		*createnode_pipex(char *array);
void		free_cmd_list(t_cmd *head);
void		proc(char *cmd, char **env, t_pipe pip, t_minishell *mini);
int			exec(char *cmd, t_minishell *mini, t_pipe *pip);
int			is_builtin(char *cmd_args);
void		pre_exec(t_command *cmd, t_pipe *pipex);
void		start_exec(t_pipe *pipex, t_minishell *minishell);
int			token_check(t_minishell *minishell);
void		check_redir(t_command *cmd, t_pipe *pipex);
int			is_redir(t_token token);
void		heredoc(char *delim);

#endif
