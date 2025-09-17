/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:24:21 by dmoraled          #+#    #+#             */
/*   Updated: 2025/06/19 13:09:08 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_dup(char **env)
{
	int		n;
	char	**ret;

	n = tab_length(env);
	ret = ft_calloc((n + 1), sizeof(char *));
	if (!ret)
		return (0);
	n = 0;
	while (env[n])
	{
		ret[n] = ft_strdup(env[n]);
		if (!ret[n])
			return (0);
		++n;
	}
	return (ret);
}

int	env_set(char *var, char *val, t_minishell *ms)
{
	char	*nv;
	char	**prev;

	if (!check_var_name(var))
		return (0);
	nv = ft_strsjoin(var, val, '=');
	if (!nv)
		return (0);
	prev = env_find(var, ms->env);
	if (!prev)
	{
		ms->env = env_add(ms->env, nv);
		if (!ms->env)
			return (0);
	}
	else
	{
		free(*prev);
		*prev = nv;
	}
	return (1);
}

char	**env_add(char **env, char *newvar)
{
	int		n;
	char	**ret;

	n = tab_length(env);
	ret = ft_calloc((n + 2), sizeof(char *));
	if (!ret)
		return (0);
	n = 0;
	while (env[n])
	{
		ret[n] = env[n];
		++n;
	}
	ret[n] = newvar;
	free(env);
	return (ret);
}

char	**env_find(char *var, char **env)
{
	int	l;

	l = ft_strlen(var);
	while (*env)
	{
		if (ft_strncmp(*env, var, l) == 0
			&& (*env)[l] == '=')
			return (env);
		++env;
	}
	return (0);
}

int	env_remove(char *var, char **env)
{
	char	**curr;

	curr = env_find(var, env);
	if (!curr)
		return (0);
	free(curr[0]);
	while (curr[0])
	{
		curr[0] = curr[1];
		++curr;
	}
	return (1);
}
