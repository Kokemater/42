/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:39:05 by dmoraled          #+#    #+#             */
/*   Updated: 2025/07/15 15:12:49 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	unset_main(char **argv, t_minishell *ms)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		env_remove(argv[i], ms->env);
		++i;
	}
	return (0);
}
