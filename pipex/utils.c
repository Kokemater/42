/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:55:08 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/04 12:10:52 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

char	**get_path(char *env[])
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
			return (ft_split(&(*env)[5], ':'));
		++env;
	}
	return (0);
}

void	free_tab(char **tab)
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

char	*find_exec_path(char **path, char *name)
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
