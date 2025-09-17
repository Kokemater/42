/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:33:32 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/15 12:41:57 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	update_pwd_vars(t_minishell *ms)
{
	char	*old;
	char	**hasold;
	char	cwd[4096];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("cd");
		return (1);
	}
	old = var_from_env("PWD", ms->env);
	if (!old)
		return (env_remove("OLDPWD", ms->env), 0);
	env_set("PWD", cwd, ms);
	hasold = env_find("OLDPWD", ms->env);
	if (hasold)
		env_set("OLDPWD", old, ms);
	free(old);
	return (0);
}

int	cd_main(char **argv, t_minishell *ms)
{
	char	*new;

	if (argv[1] && argv[2])
		return (ft_putendl_fd("minishell: cd: too many arguments", 2), 1);
	new = argv[1];
	if (!new)
		new = var_from_env("HOME", ms->env);
	if (!new)
	{
		err_str("cd: HOME not set\n");
		return (1);
	}
	if (chdir(new) != 0)
	{
		perror("cd");
		return (1);
	}
	if (!argv[1])
		free(new);
	return (update_pwd_vars(ms));
}
