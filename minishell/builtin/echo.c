/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:33:56 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/15 14:00:35 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	options(char **args, int *idx, int *no_endl)
{
	int	j;

	if (args[1] && args[1][0] == '-' && args[1][1] != 0)
	{
		j = 1;
		while (args[1][j])
		{
			if (args[1][j] == 'n')
			{
				*no_endl = 1;
				*idx = 2;
			}
			else
			{
				*no_endl = 0;
				*idx = 1;
				break ;
			}
			++j;
		}
	}
}

int	echo_main(char **args)
{
	int	i;
	int	no_endl;

	i = 1;
	no_endl = 0;
	options(args, &i, &no_endl);
	while (args[i])
	{
		ft_printf("%s", args[i++]);
		if (args[i])
			ft_printf(" ");
	}
	if (no_endl == 0)
		ft_printf("\n");
	return (0);
}
