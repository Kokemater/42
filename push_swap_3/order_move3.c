/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_move3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:51:33 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/04 00:52:37 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_best_move(int i_a, int i_b, t_list **a, t_list **b, int pa)
{
	int	n[2];
	int	steps_down[2];
	int	position[2];
	int	moves[3];

	n[0] = ft_lst_len(*a);
	n[1] = ft_lst_len(*b);
	steps_down[0] = n[0] - i_a;
	steps_down[1] = n[1] - i_b;
	position[0] = lst_find_node_by_index(*a, i_a)->position;
	position[1] = lst_find_node_by_index(*b, i_b)->position;
	moves[0] = moves_paralel_up(i_a, i_b);
	moves[1] = moves_paralel_down(steps_down[0], steps_down[1]);
	moves[2] = moves_no_paralel(i_a, i_b, n[0], n[1]);
	if (ft_min3(moves[0], moves[1], moves[2]) == moves[0])
		apply_moves_paralel_up(position[0], position[1], a, b);
	else if (ft_min3(moves[0], moves[1], moves[2]) == moves[1])
		apply_moves_paralel_down(position[0], position[1], a, b);
	else if (ft_min3(moves[0], moves[1], moves[2]) == moves[2])
	{
		apply_moves_no_paralel_a(position[0], i_a, a, n);
		apply_moves_no_paralel_b(position[1], i_b, b, n);
	}
	push(pa, a, b);
}