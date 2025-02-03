#include "push_swap.h"
int	n_moves(int i_a, int n_a, int current_position, t_list **b, int *i_b);

void order_2_elements(t_list **a)
{
	if ((*a)->next->position < (*a)->position)
		ra(a);
}

void order_3_elements(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->position;
	second = (*a)->next->position;
	third = (*a)->next->next->position;
	if (first < second && second < third)
		return ;
	else if (first < third && second > third)
	{
		sa(a);
		ra(a);
	}
	else if (first > third && first < second)
		rra(a);
	else if (first > second && first < third)
		sa(a);
	else if (first > second && second < third)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}


int	next_to_number_min(int n, t_list *b)
{
	int		next_to_number;
	t_list	*current;

	current = b;
	next_to_number = -1;
	while (current)
	{
		if (current->position < n &&
			(next_to_number == -1 || current->position > next_to_number))
			next_to_number = current->position;
		current = current->next;
	}
	if (next_to_number == -1)
		next_to_number = lst_find_max_position(b);
	return (next_to_number);
}




void place_element_in_top_a(int i_a, int n_a, t_list **a, int *a_moves)
{
	if (i_a <= n_a/2)
		ra(a);
	else
		rra(a);
	(*a_moves)--;
}
void place_element_in_top_b(int i_a, int n_a, t_list **a, int *b_moves)
{
	int	i;

	i = 0;
	if (i_a <=  n_a/2)
		rb(a);
	else
		rrb(a);
	(*b_moves)--;
}

void	apply_moves_paralel_up(int a_position, int b_position, t_list **a, t_list **b)
{
	while (((*a)->position != a_position && (*b)->position != b_position))
		rr(a, b);
	while ((*a)->position != a_position)
		ra(a);
	while ((*b)->position != b_position)
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
		if (i_a < n[0] /2)
			ra(a);
		else
			rra(a);
	}
}
void	apply_moves_no_paralel_b(int b_position, int i_b, t_list **b, int *n)
{
	while ((*b)->position != b_position)
	{
		if (i_b < n[1]/ 2)
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
int moves_no_paralel(int i_a, int i_b, int n_a, int n_b)
{
	int	moves_a;
	int	moves_b;

	moves_b = n_b/2.0 - ft_abs(i_b - n_b/2.0);
	moves_a = n_a/2.0 - ft_abs(i_a - n_a/2.0);
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
void	apply_best_move(int i_a, int i_b, t_list **a, t_list **b, int push_to_a)
{
	int	n[2];
	int	steps_down[2];
	int	position[2];
	int	moves[3]; // Paralel_up, Paralel_down , No paralel

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
	push(push_to_a, a, b);
}

void make_minimizer_move(t_list **a, t_list **b)
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


//////////////////////////////////////////////////////////////////////////
int	next_to_number_max(int n, t_list *b)
{
	int		next_to_number;
	t_list	*current;

	current = b;
	next_to_number = -1;

	while (current)
	{
		if (current->position > n &&
			(next_to_number == -1 || current->position < next_to_number))
			next_to_number = current->position;
		current = current->next;
	}
	if (next_to_number == -1)
		next_to_number = lst_find_min_position(b);
	return (next_to_number);
}


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

void make_minimizer_move2(t_list **a, t_list **b)
{
	t_list	*curr_n;
	int		curr[2];
	int		i[2];
	int		best_moves_n_moves;
	int		move;

	curr[1] = 0;
	curr_n = *b;
	i[0] = -1;
	i[1] = 0;
	best_moves_n_moves = 10000;
	while (curr_n)
	{
		move = n_moves2(curr[1], ft_lst_len(*b), curr_n->position, a, &curr[0]);
		if (move < best_moves_n_moves)
		{
			best_moves_n_moves = move;
			i[0] = curr[0];
			i[1] = curr[1];
		}
		curr_n = curr_n->next;
		curr[1]++;
	}
	apply_best_move(i[0], i[1], a, b, 1);
}

void order_list(t_list **a, t_list **b)
{
	int	len;
	int	i;
	int	cero_index;

	len = ft_lst_len(*a);
	if (ft_lst_len(*a) == 2)
		order_2_elements(a);
	pb(a, b);
	while (ft_lst_len(*a) > 3)
		make_minimizer_move(a, b);
	order_3_elements(a);
	while (ft_lst_len(*b) > 0)
		make_minimizer_move2(a, b);
	cero_index = lst_find_index_by_position(*a, 0);
	if (cero_index < len/ 2)
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
