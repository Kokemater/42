/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:50:24 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 13:50:40 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	repeated_nums(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (atoi(argv[i]) == atoi(argv[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	inspect_errors(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!is_a_number(argv[i]))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	if (repeated_nums(argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
