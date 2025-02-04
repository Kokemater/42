/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_n_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:29:52 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/04 10:29:58 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_moves2(int i_a, int n_a, int current_position, t_list **b, int *i_b)
{
	int	next_to_number;
	int	steps_up[2];
	int	steps_down[2];
	int	moves[3];
	int	n_b;

	next_to_number = next_to_number_max(current_position, *b);
	*i_b = lst_find_index_by_position(*b, next_to_number);
	n_b = ft_lst_len(*b);
	steps_up[0] = i_a;
	steps_down[0] = n_a - i_a;
	steps_up[1] = *i_b;
	steps_down[1] = n_b - *i_b;
	moves[0] = moves_paralel_up(steps_up[0], steps_up[1]);
	moves[1] = moves_paralel_down(steps_down[0], steps_down[1]);
	moves[2] = moves_no_paralel(i_a, *i_b, n_a, n_b);
	return (ft_min3(moves[0], moves[1], moves[2]));
}

int	n_moves(int i_a, int n_a, int current_position, t_list **b, int *i_b)
{
	int	next_to_number;
	int	steps_up[2];
	int	steps_down[2];
	int	moves[3];
	int	n_b;

	next_to_number = next_to_number_min(current_position, *b);
	*i_b = lst_find_index_by_position(*b, next_to_number);
	n_b = ft_lst_len(*b);
	steps_up[0] = i_a;
	steps_down[0] = n_a - i_a;
	steps_up[1] = *i_b;
	steps_down[1] = n_b - *i_b;

	moves[0] = moves_paralel_up(steps_up[0], steps_up[1]);
	moves[1] = moves_paralel_down(steps_down[0], steps_down[1]);
	moves[2] = moves_no_paralel(i_a, *i_b, n_a, n_b);
	return (ft_min3(moves[0], moves[1], moves[2]));
}
