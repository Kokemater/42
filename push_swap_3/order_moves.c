#include "push_swap.h"

void	place_element_in_top_a(int i_a, int n_a, t_list **a, int *a_moves)
{
	if (i_a <= n_a / 2)
		ra(a);
	else
		rra(a);
	(*a_moves)--;
}

void	place_element_in_top_b(int i_a, int n_a, t_list **a, int *b_moves)
{
	int	i;

	i = 0;
	if (i_a <= n_a / 2)
		rb(a);
	else
		rrb(a);
	(*b_moves)--;
}

void	apply_moves_paralel_up(int a_pos, int b_pos, t_list **a, t_list **b)
{
	while (((*a)->position != a_pos && (*b)->position != b_pos))
		rr(a, b);
	while ((*a)->position != a_pos)
		ra(a);
	while ((*b)->position != b_pos)
		rb(b);
}

void	apply_moves_paralel_down(int a_pos, int b_pos, t_list **a, t_list **b)
{
	while (((*a)->position != a_pos && (*b)->position != b_pos))
		rrr(a, b);
	while ((*a)->position != a_pos)
		rra(a);
	while ((*b)->position != b_pos)
		rrb(b);
}

void	apply_moves_no_paralel_a(int a_position, int i_a, t_list **a, int *n)
{
	while ((*a)->position != a_position)
	{
		if (i_a < n[0] / 2)
			ra(a);
		else
			rra(a);
	}
}
