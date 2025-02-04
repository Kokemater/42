/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:49:32 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/04 10:00:11 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_minimizer_move(t_list **a, t_list **b)
{
	t_list	*curr_n;
	int		curr[2];
	int		i[2];
	int		best_moves_n_moves;
	int		moves;

	curr[0] = 0;
	curr_n = *a;
	i[0] = 0;
	i[1] = -1;
	best_moves_n_moves = 10000;
	while (curr_n)
	{
		moves = n_moves(curr[0], ft_lst_len(*a), curr_n->position, b, &curr[1]);
		if (moves < best_moves_n_moves)
		{
			best_moves_n_moves = moves;
			i[0] = curr[0];
			i[1] = curr[1];
		}
		curr_n = curr_n->next;
		curr[0]++;
	}
	apply_best_move(i[0], i[1], a, b, 0);
}

static void	order_more_elements(t_list **a, t_list **b, int len)
{
	int cero_index;

	pb(a, b);
	while (ft_lst_len(*a) > 3)
		make_minimizer_move(a, b);
	order_3_elements(a);
	while (ft_lst_len(*b) > 0)
		pa(a, b);
	cero_index = lst_find_index_by_position(*a, 0);
	if (cero_index < len / 2)
	{
		while ((*a)->position != 0)
			ra(a);
	}
	else
	{
		while ((*a)->position != 0)
			rra(a);
	}
	}
void	order_list(t_list **a, t_list **b)
{
	int	len;

	len = ft_lst_len(*a);
	if (ft_lst_len(*a) == 1)
		return ;
	if (ft_lst_len(*a) == 2)
		order_2_elements(a);
	else if (ft_lst_len(*a) == 3)
		order_3_elements(a);
	else
	{
		order_more_elements(a, b, len);
	}

}
