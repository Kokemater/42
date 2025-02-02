#include "push_swap.h"


void order_2_elements(t_list **a)
{
	if ((*a)->next->position < (*a)->position)
		sa(a);
}

void order_3_elements(t_list **a, t_list **b)
{
	if ((*a)->position > (*a)->next->position && (*a)->next->position < (*a)->next->next->position)
		sa(a);
	else if ((*a)->position > (*a)->next->position && (*a)->next->position > (*a)->next->next->position)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->position > (*a)->next->next->position && (*a)->next->position < (*a)->next->next->position)
		ra(a);
	else if ((*a)->position > (*a)->next->next->position && (*a)->next->position > (*a)->next->next->position)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->position < (*a)->next->position && (*a)->next->position > (*a)->next->next->position)
		rra(a);
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
	int n_b = ft_lst_len(*b);
	*i_b = lst_find_index_by_position(*b, next_to_number);

	return ((n_b/2.0 - ft_abs(*i_b - n_b/2.0)) + (n_a/2.0 - ft_abs(i_a - n_a/2.0)));
}



void place_element_in_top_a(int i_a, int n_a, t_list **a)
{
	int a_moves = (n_a/2.0 - ft_abs(i_a - n_a/2.0));
	//printf("a_moves = %d \n", a_moves);

	int i = 0;
	if (i_a <= n_a/2)
	{
		while (i < a_moves)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < a_moves)
		{
			rra(a);
			i++;
		}
	}
}
void place_element_in_top_b(int i_a, int n_a, t_list **a)
{

	int b_moves = (n_a/2.0 - ft_abs(i_a - n_a/2.0));
	//printf("b_moves = %d \n", b_moves);

	int i = 0;
	if (i_a <=  n_a/2)
	{
		while (i < b_moves)
		{
			rb(a);
			i++;
		}
	}
	else
	{
		while (i < b_moves)
		{
			rrb(a);
			i++;
		}
	}
}

void apply_best_move(int i_a, int i_b, t_list **a, t_list **b)
{
	int n_a = ft_lst_len(*a);
	int n_b = ft_lst_len(*b);
	int b_moves = (n_b/2.0 - ft_abs(i_b - n_b/2.0));
	int i = 0;

	// put a_el in the top
	place_element_in_top_a(i_a, n_a, a);
	place_element_in_top_b(i_b, n_b, b);
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
	apply_best_move(i_a, i_b, a, b);
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
	int n_b = ft_lst_len(*b);
	*i_b = lst_find_index_by_position(*b, next_to_number);

	return ((n_b/2.0 - ft_abs(*i_b - n_b/2.0)) + (n_a/2.0 - ft_abs(i_a - n_a/2.0)));
}


void apply_best_move2(int i_a, int i_b, t_list **a, t_list **b)
{
	int n_a = ft_lst_len(*a);
	int n_b = ft_lst_len(*b);
	int b_moves = (n_b/2.0 - ft_abs(i_b - n_b/2.0));
	int i = 0;

	// put a_el in the top
	place_element_in_top_a(i_a, n_a, a);
	place_element_in_top_b(i_b, n_b, b);
	pa(a, b);
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
	apply_best_move2(i_a, i_b, a, b);
}

void order_list(t_list **a, t_list **b)
{
	int	len;
	int	i;
	len = ft_lst_len(*a);
	if (is_ordered(*a))
		return ;
	if (ft_lst_len(*a) == 2)
		order_2_elements(a);
		//printf("hola");
	pb(a, b);
	while (ft_lst_len(*a) > len/2)
		make_minimizer_move(a, b);
	while (ft_lst_len(*a) > 1)
		pb(a, b);
	while (ft_lst_len(*b) > 0)
		make_minimizer_move2(a, b);
	while((*a)->position != 0)
		ra(a);

}