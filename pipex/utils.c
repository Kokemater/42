/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:55:08 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/05 00:59:00 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	return_value(int last_ret, int io[2])
{
	int	v;

	if (WIFEXITED(last_ret))
		v = WEXITSTATUS(last_ret);
	if (io[1] < 0)
		v = 1;
	return (v);
}

char	**get_path(char *env[])
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
			return (ft_split(&(*env)[5], ':'));
		env++;
	}
	return (0);
}

void	free_all(char **tab)
{
	char	**p;

	if (!tab)
		return ;
	p = tab;
	while (*p)
	{
		free(*p);
		p++;
	}
	free(tab);
}

char	*exec_path_finder(char **path, char *name)
{
	char	*full_path;

	while (*path)
	{
		full_path = ft_strjoin_sep(*path, name, '/');
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		++path;
	}
	if (access(name, X_OK) == 0)
		return (ft_strdup(name));
	return (0);
}
