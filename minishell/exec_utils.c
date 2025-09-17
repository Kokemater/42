/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:43:57 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/14 13:28:22 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	path_error(char *path, char *name)
{
	struct stat	st;

	if (!path || stat(path, &st) == -1)
	{
		if (ft_strchr(name, '/'))
			err_str2(name, ": No such file or directory\n", 0);
		else
			err_str2(name, ": command not found\n", 0);
		return (127);
	}
	if (S_ISDIR(st.st_mode))
		return (err_str2(path, ": Is a directory\n", 0), 126);
	if (access(path, X_OK) != 0)
		return (err_str2(path, ": Permission denied\n", 0), 126);
	return (0);
}

static char	*try_path(char *name, char **path)
{
	char	*full_path;

	full_path = 0;
	if (!ft_strchr(name, '/') && path)
	{
		while (*path)
		{
			full_path = ft_strsjoin(*path, name, '/');
			if (access(full_path, F_OK) == 0)
				break ;
			free(full_path);
			full_path = 0;
			++path;
		}
	}
	else
		full_path = ft_strdup(name);
	return (full_path);
}

char	*find_exec_path(char *name, t_minishell *ms)
{
	char	*full_path;
	int		error;
	char	**path;

	path = path_from_env(ms->env);
	full_path = try_path(name, path);
	if (path)
		tab_free(path);
	error = path_error(full_path, name);
	if (error)
	{
		minishell_exit(ms, error);
		free(full_path);
		full_path = 0;
	}
	return (full_path);
}

t_cmd	*cmd_last(t_cmd *cmd)
{
	while (cmd)
	{
		if (cmd->next)
			cmd = cmd->next;
		else
			return (cmd);
	}
	return (0);
}
