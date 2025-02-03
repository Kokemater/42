#include "push_swap.h"


void order_2_elements(t_list **a)
{
	if ((*a)->next->position < (*a)->position)
		sa(a);
}

void order_3_elements(t_list **a)
{
	int first = (*a)->position;
	int second = (*a)->next->position;
	int third = (*a)->next->next->position;

	// 1 2 3 - ya está ordenado
	if (first < second && second < third)
		return;
	// 1 3 2
	else if (first < third && second > third)
	{
		sa(a);
		ra(a);
	}
	// 2 3 1
	else if (first > third && first < second)
		rra(a);
	// 2 1 3
	else if (first > second && first < third)
		sa(a);
	// 3 1 2
	else if (first > second && second < third)
		ra(a);
	// 3 2 1
	else
	{
		sa(a);
		rra(a);
	}
}


int is_ordered(t_list *a)
{
	if (ft_lst_len(a) == 0)
		return (0);
	while(a && a->next)
	{
		if (a->position > a->next->position)
			return (0);
		a = a->next;
	}
	return (1);
}

int	next_to_number_min(int n, t_list *b)
{
    int next_to_number = -1;
    t_list *current = b;

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


void place_element_in_top_a(int i_a, int n_a, t_list **a, int *a_moves)
{
	if (i_a <= n_a/2)
	{
		ra(a);
	}
	else
	{
		rra(a);
	}
	(*a_moves)--;
}
void place_element_in_top_b(int i_a, int n_a, t_list **a, int *b_moves)
{
	int i = 0;
	if (i_a <=  n_a/2)
	{
			rb(a);
	}
	else
	{
			rrb(a);
	}
	(*b_moves)--;

}

void apply_best_move(int i_a, int i_b, t_list **a, t_list **b, int push_to_a)
{
	int n_a = ft_lst_len(*a);
	int n_b = ft_lst_len(*b);
	int steps_up_a = i_a;
	int steps_down_a = n_a - i_a;
	int steps_up_b = i_b;
	int steps_down_b = n_b - i_b;
	int moves_paralel_up = ft_min(steps_up_a, steps_up_b) + ft_abs(ft_max(steps_up_a, steps_up_b) - ft_min(steps_up_a, steps_up_b));
	int moves_paralel_down = ft_min(steps_down_a, steps_down_b) + ft_abs(ft_max(steps_down_a, steps_down_b) - ft_min(steps_down_a, steps_down_b)); 
	int moves_no_paralel = (n_b/2.0 - ft_abs(i_b - n_b/2.0)) + (n_a/2.0 - ft_abs(i_a - n_a/2.0));

	int a_position = lst_find_node_by_index(*a, i_a)->position;
	int b_position = lst_find_node_by_index(*b, i_b)->position;

	// put a_el in the top
		if (ft_min3(moves_paralel_up, moves_paralel_down, moves_no_paralel) == moves_paralel_up)
		{
			//printf("Paralel up \n");

			while (((*a)->position != a_position && (*b)->position != b_position))
				rr(a, b);
			while ((*a)->position != a_position)
				ra(a);
			while ((*b)->position != b_position)
				rb(b);

		}
		else if (ft_min3(moves_paralel_up, moves_paralel_down, moves_no_paralel) == moves_paralel_down)
		{
					//printf("Paralel down \n");

			while (((*a)->position != a_position && (*b)->position != b_position))
				rrr(a, b);
			while ((*a)->position != a_position)
				rra(a);
			while ((*b)->position != b_position)
				rrb(b);
		}
		else if (ft_min3(moves_paralel_up, moves_paralel_down, moves_no_paralel) == moves_no_paralel)
		{
					//printf("No paralel \n");

			while ((*a)->position != a_position)
			{
				if (i_a < n_a/2)
					ra(a);
				else
					rra(a);
			}
			while ((*b)->position != b_position)
			{
				if (i_b < n_b/2)
					rb(b);
				else
					rrb(b);
			}

		}

	if (push_to_a)
		pa(a, b);
	else
		pb(a, b);
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
	if (is_ordered(*a))
		return ;
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