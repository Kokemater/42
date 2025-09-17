/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:39:12 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/14 15:25:02 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	add_var(char *var, t_minishell *ms)
{
	char	*eq;

	eq = ft_strchr(var, '=');
	if (!eq && !check_var_name(var))
		return (0);
	if (!eq && check_var_name(var))
		return (1);
	*eq = 0;
	if (!env_set(var, eq + 1, ms))
		return (0);
	return (1);
}

void	print_env(char **env)
{
	char	*eq;
	char	r;

	while (*env)
	{
		ft_putstr_fd("declare -x ", 1);
		eq = ft_strchr(*env, '=');
		r = eq[1];
		eq[1] = 0;
		ft_putstr_fd(*env, 1);
		eq[1] = r;
		ft_putchar_fd('"', 1);
		ft_putstr_fd(eq + 1, 1);
		ft_putendl_fd("\"", 1);
		++env;
	}
}

int	export_main(char **argv, t_minishell *ms)
{
	if (!argv[1])
	{
		print_env(ms->env);
		return (0);
	}
	++argv;
	while (*argv)
	{
		if (!add_var(*argv, ms))
		{
			err_str("export: not a valid identifier\n");
			return (1);
		}
		++argv;
	}
	return (0);
}
