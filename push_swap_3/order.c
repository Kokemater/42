#include "push_swap.h"


void order_2_elements(t_list **a)
{
	if ((*a)->next->position < (*a)->position)
		sa(a);
}

void order_3_elements(t_list **a)
{
	int first;
	int second;
	int third;

	first = (*a)->position;
	second = (*a)->next->position;
	third = (*a)->next->next->position;
	if (first < second && second < third)
		return;
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
    int next_to_number;
    t_list *current;

	current = b;
	next_to_number = -1;
    while (current)
    {
        if (current->position < n && (next_to_number == -1 || current->position > next_to_number))
            next_to_number = current->position;
        current = current->next;
    }
    if (next_to_number == -1)
        next_to_number = lst_find_max_position(b);
    return (next_to_number);
}


int	calculate_moves(int i_a, int n_a, int current_position, t_list **b, int *i_b)
{
	int next_to_number = next_to_number_min(current_position, *b);
	*i_b = lst_find_index_by_position(*b, next_to_number);


	int n_b = ft_lst_len(*b);
	int steps_up_a = i_a;
	int steps_down_a = n_a - i_a;
	int steps_up_b = *i_b;
	int steps_down_b = n_b - *i_b;
	int moves_paralel_up = ft_min(steps_up_a, steps_up_b) + ft_abs(ft_max(steps_up_a, steps_up_b) - ft_min(steps_up_a, steps_up_b));
	int moves_paralel_down = ft_min(steps_down_a, steps_down_b) + ft_abs(ft_max(steps_down_a, steps_down_b) - ft_min(steps_down_a, steps_down_b)); 
	int moves_no_paralel = (n_b/2.0 - ft_abs(*i_b - n_b/2.0)) + (n_a/2.0 - ft_abs(i_a - n_a/2.0));

	return (ft_min3(moves_paralel_up, moves_paralel_down, moves_no_paralel));
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
void	apply_moves_paralel_down(int a_position, int b_position, t_list **a, t_list **b)
{
	while (((*a)->position != a_position && (*b)->position != b_position))
		rrr(a, b);
	while ((*a)->position != a_position)
		rra(a);
	while ((*b)->position != b_position)
		rrb(b);
}
void	apply_moves_no_paralel_a(int a_position, int i_a, t_list **a, int *n)
{
	while ((*a)->position != a_position)
	{
		if (i_a < n[0]/2)
			ra(a);
		else
			rra(a);
	}
}
void	apply_moves_no_paralel_b(int b_position, int i_b, t_list **b, int *n)
{
	while ((*b)->position != b_position)
	{
		if (i_b < n[1]/2)
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

void apply_best_move(int i_a, int i_b, t_list **a, t_list **b, int push_to_a)
{
	int	n[2];
	int	steps_down[2];
	int position[2];
	int moves[3]; // Paralel_up, Paralel_down , No paralel

	n[0] = ft_lst_len(*a);
	n[1] = ft_lst_len(*b);
	steps_down[0] = n[0] - i_a;
	steps_down[1] = n[1] - i_b;
	position[0] = lst_find_node_by_index(*a, i_a)->position;
	position[1] = lst_find_node_by_index(*b, i_b)->position;
	moves[0] = ft_min(i_a, i_b) + ft_abs(ft_max(i_a, i_b) - ft_min(i_a, i_b));
	moves[1] = ft_min(steps_down[0], steps_down[1]) + ft_abs(ft_max(steps_down[0], steps_down[1]) - ft_min(steps_down[0], steps_down[1])); 
	moves[2] = (n[1]/2.0 - ft_abs(i_b - n[1]/2.0)) + (n[0]/2.0 - ft_abs(i_a - n[0]/2.0));
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
    t_list	*current;
    int     current_ia;
	int		current_ib;
    int		i_a;
	int		i_b = -1;
	int		best_moves_n_moves;

    current_ia = 0;
    current = *a;
    i_a = 0;
    best_moves_n_moves = 10000;
	//print_list(*a, *b);
    while (current)
    {
        int moves = calculate_moves(current_ia, ft_lst_len(*a), current->position, b, &current_ib);
        if (moves < best_moves_n_moves)
        {
            best_moves_n_moves = moves;
            i_a = current_ia;
			i_b = current_ib;
        }
        current = current->next;
        current_ia++;
    }
	//printf("i_a : %d \n, i_b : %d \n", i_a, i_b);
	apply_best_move(i_a, i_b, a, b, 0);
}


//////////////////////////////////////////////////////////////////////////
int	next_to_number_max(int n, t_list *b)
{
    int next_to_number = -1;
    t_list *current = b;

    while (current)
    {
        if (current->position > n && (next_to_number == -1 || current->position < next_to_number))
            next_to_number = current->position;
        current = current->next;
    }
    if (next_to_number == -1)
        next_to_number = lst_find_min_position(b);
    return (next_to_number);
}


int	calculate_moves2(int i_a, int n_a, int current_position, t_list **b, int *i_b)
{
	int next_to_number = next_to_number_max(current_position, *b);
	//printf("Next to number %d \n", next_to_number);
	*i_b = lst_find_index_by_position(*b, next_to_number);


	int n_b = ft_lst_len(*b);
	int steps_up_a = i_a;
	int steps_down_a = n_a - i_a;
	int steps_up_b = *i_b;
	int steps_down_b = n_b - *i_b;
	int moves_paralel_up = ft_min(steps_up_a, steps_up_b) + ft_abs(ft_max(steps_up_a, steps_up_b) - ft_min(steps_up_a, steps_up_b));
	int moves_paralel_down = ft_min(steps_down_a, steps_down_b) + ft_abs(ft_max(steps_down_a, steps_down_b) - ft_min(steps_down_a, steps_down_b)); 
	int moves_no_paralel = (n_b/2.0 - ft_abs(*i_b - n_b/2.0)) + (n_a/2.0 - ft_abs(i_a - n_a/2.0));

	return (ft_min3(moves_paralel_up, moves_paralel_down, moves_no_paralel));
}





void make_minimizer_move2(t_list **a, t_list **b)
{
    t_list	*current;
	int		current_ia;
	int		current_ib;
	int		i_a = -1;
	int		i_b;
	int		best_moves_n_moves;

    current_ib = 0;
    current = *b;
    i_b = 0;
    best_moves_n_moves = 10000;
	//print_list(*a, *b);
    while (current)
    {
        int moves = calculate_moves2(current_ib, ft_lst_len(*b), current->position, a, &current_ia);
        if (moves < best_moves_n_moves)
        {
			best_moves_n_moves = moves;
			i_a = current_ia;
			i_b = current_ib;
        }
        current = current->next;
        current_ib++;
    }
	//printf("i_a : %d \n, i_b : %d \n", i_a, i_b);
	apply_best_move(i_a, i_b, a, b, 1);
}

void order_list(t_list **a, t_list **b)
{
	int	len;
	int	i;
	//print_list(*a, *b);
	len = ft_lst_len(*a);
	if (ft_lst_len(*a) == 2)
		order_2_elements(a);
		//printf("hola");
	pb(a, b);
	while (ft_lst_len(*a) > 3)
		make_minimizer_move(a, b);
	while (ft_lst_len(*a) > 3)
		pb(a, b);
	order_3_elements(a);
	while (ft_lst_len(*b) > 0)
		make_minimizer_move2(a, b);
	int cero_index = lst_find_index_by_position(*a, 0);
	if (cero_index < len/2)
	{
		while((*a)->position != 0)
			ra(a);
	}
	else
	{
		while((*a)->position != 0)
			rra(a);
	}
	//print_list(*a, *b);
	

}