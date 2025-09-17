/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:34:06 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/14 15:48:54 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exit_main(char **args)
{
	ft_putstr_fd("exit\n", 1);
	if (args[1] && !ft_isnum(args[1]))
	{
		ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
		return (2);
	}
	else if (args[1])
	{
		if (args[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return (1);
		}
		return (ft_atoi(args[1]));
	}
	return (0);
}
