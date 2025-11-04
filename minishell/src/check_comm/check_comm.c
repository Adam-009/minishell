/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:05:36 by asaadi--          #+#    #+#             */
/*   Updated: 2025/04/22 10:23:31 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

char	**find_path(char **env)
{
	int		i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (ft_split(&env[i][5], ':'));
		i++;
	}
	return (NULL);
}

char	*comm_without_arg(char *command)
{
	int	i;

	i = 0;
	while (command[i] && command[i] != ' ')
		i++;
	return (ft_substr(command, 0, i));
}

char	*check_full_path(char *path)
{
	if (access(path, F_OK | X_OK) == 0)
		return (ft_strdup(path));
	return (NULL);
}

char	*check_if_exist(char *comm, char **paths)
{
	int		i;
	char	*tmp_path;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		tmp_path = ft_strjoin("/", comm);
		if (!tmp_path)
			return (NULL);
		full_path = ft_strjoin(paths[i], tmp_path);
		free(tmp_path);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*check_comm(char *command, char **env)
{
	char	**paths;
	char	*comm;
	char	*path;

	if (command[0] == '/')
		return (handle_direct_path(command));
	paths = find_path(env);
	comm = comm_without_arg(command);
	if (!comm || !paths)
	{
		free_everything(comm, paths);
		return (NULL);
	}
	path = check_if_exist(comm, paths);
	if (!path || comm[0] == '\0')
	{
		if (path)
			free(path);
		error_msg_comm("Command error: ", command);
		free_everything(comm, paths);
		return (NULL);
	}
	free_everything(comm, paths);
	return (path);
}
