/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:57:02 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/14 15:36:59 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**path_from_env(char *env[])
{
	char	*path;
	char	**ret;

	path = var_from_env("PATH", env);
	if (!path)
		return (0);
	ret = ft_split(path, ':');
	if (!ret)
		return (0);
	free(path);
	return (ret);
}

char	*var_from_env(char *var, char *env[])
{
	int	l;

	l = ft_strlen(var);
	while (*env)
	{
		if (ft_strncmp(*env, var, l) == 0
			&& (*env)[l] == '=')
			return (ft_strdup(&(*env)[l + 1]));
		++env;
	}
	return (0);
}

char	*ft_earlier(char *a, char *b)
{
	if (!a && !b)
		return (0);
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (a < b)
		return (a);
	return (b);
}

void	minishell_exit(t_minishell *ms, int code)
{
	ms->exit = 1;
	ms->excode = code;
}

int	ft_issspace(char *s)
{
	while (*s)
	{
		if (!ft_isspace(*s))
			return (0);
		++s;
	}
	return (1);
}
