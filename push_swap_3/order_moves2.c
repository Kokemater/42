/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_moves2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:15:18 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/04 09:15:19 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_moves_no_paralel_b(int b_position, int i_b, t_list **b, int *n)
{
	while ((*b)->position != b_position)
	{
		if (i_b < n[1] / 2)
			rb(b);
		else
			rrb(b);
	}
}

void	push(int push_to_a, t_list **a, t_list **b)
{
	if (push_to_a)
		pa(a, b);
	else
		pb(a, b);
}

int	moves_no_paralel(int i_a, int i_b, int n_a, int n_b)
{
	int	moves_a;
	int	moves_b;

	moves_b = n_b / 2.0 - ft_abs(i_b - n_b / 2.0);
	moves_a = n_a / 2.0 - ft_abs(i_a - n_a / 2.0);
	return (moves_a + moves_b);
}

int	moves_paralel_down(int steps_down_a, int steps_down_b)
{
	int	moves_a;
	int	moves_b;
	int	paralel;

	moves_a = ft_min(steps_down_a, steps_down_b);
	moves_b = ft_abs(ft_max(steps_down_a, steps_down_b));
	paralel = ft_min(steps_down_a, steps_down_b);
	return (moves_a + moves_b - paralel);
}

int	moves_paralel_up(int i_a, int i_b)
{
	return (ft_min(i_a, i_b) + ft_abs(ft_max(i_a, i_b) - ft_min(i_a, i_b)));
}
