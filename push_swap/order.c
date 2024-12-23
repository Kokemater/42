#include "push_swap.h"


void order_2_elements(t_list **a)
{
	if ((*a)->next->position < (*a)->position)
		sa(a);
}

void order_3_elements(t_list **a, t_list **b)
{
	return ;
}

int ordered(t_list *a)
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

int is_buitripiramide(t_list *a)
{
	int		upper_height;
	int		lower_height;
	int		num_of_peaks;
	int		i;
	t_list	*tmp;

	tmp = a;
	if (!tmp || !(tmp->next))
		return (0);
	upper_height = 1;
	lower_height = 1;
	while (tmp->next && tmp->position > tmp->next->position)
	{
		tmp = tmp->next;
		upper_height++;
	}
	tmp = ft_lstlast(a);
	tmp = lst_prev_node(a, tmp);

	while (tmp && tmp->next && tmp->position < tmp->next->position)
	{
		tmp = lst_prev_node(tmp, a);
		lower_height++;
	}
	// //printf("%d asdfasdf %d \n ", upper_height, lower_height);
	i = ft_lst_len(a) - (upper_height + lower_height);
	num_of_peaks = 0;
	tmp = lst_find_node_by_index(a, upper_height);
	// //printf("%d yyeye \n", tmp->position);
	while(i > 0)
	{
		if (tmp->position > tmp->next->position)
			num_of_peaks++;
		i--;
		tmp = tmp->next;
		// //printf("number_of_peaks : %d \n", num_of_peaks);
		if (num_of_peaks > 1)
			return (0);
	}
	return (1);	
}

void change_comparisons(int *find_bigger, int top_bigger, int *move_pos, int last_move_pos, t_list **current_stack)
{

	if (*find_bigger)
		{
			if(top_bigger)
			{
				*move_pos = head_position(*current_stack);
				if (*move_pos > last_move_pos)
				{
					*find_bigger = !(*find_bigger);
				}
			}
			else
			{
				*move_pos = tail_position(*current_stack);
				if ( *move_pos > last_move_pos)
				{
					*find_bigger = !(*find_bigger);
				}
			}		
		}
		else
		{
			if (top_bigger)
			{
				*move_pos = tail_position(*current_stack);
				if (*move_pos < last_move_pos)
				{
					*find_bigger = !(*find_bigger);
				}
			}
			else
			{
				*move_pos = head_position(*current_stack);
				if (*move_pos < last_move_pos)
				{
					*find_bigger = !(*find_bigger);
				}
			}		
		}
}


void morales_movements(int in_a, int find_bigger, int last_move_pos, t_list **a, t_list **b)
{
	int top_bigger;
	int	move_top;
	int	move_pos;
	int	change;
	t_list	**current_stack;

	change = 1;
	if (in_a)
		current_stack = a;
	else
		current_stack = b;
	int i = 0;
	while(!ordered(*a))
	{
		while (ft_lst_len(*current_stack) > 0)
		{
			if (head_position(*current_stack) > tail_position(*current_stack))
				top_bigger = 1;
			else
				top_bigger = 0;
			change_comparisons(&find_bigger, top_bigger, &move_pos, last_move_pos, current_stack);
			if ((top_bigger && find_bigger) || (!top_bigger && !find_bigger))
				move_top = 1;
			if ((!top_bigger && find_bigger) || (top_bigger && !find_bigger))
				move_top = 0;
			change_container(in_a, move_top, a, b);
			last_move_pos = move_pos;
		}
		in_a = !in_a;
		if (in_a)
			current_stack = a;
		else
			current_stack = b;
		find_bigger = 1;
		last_move_pos = 1000;
		i++;
		if (is_buitripiramide(*a) && ft_lst_len(*a))
			break ;

	}
}

void convert_2_buipiramide(t_list **a, t_list **b)
{
	int	middle;
	int	i;
	int	top_bigger;
	int size;

	i = 0;
	size = ft_lst_len(*a);
	middle = size/2;
	while(i < size)
	{
		if (head_position(*a) > tail_position(*a))
			top_bigger = 1;
		else
			top_bigger = 0;
		if (i <= middle) // IMPORTANTE el igual (revisar)
		{
			change_container(1, top_bigger, a, b); // Move big

		}
		else
		{
			change_container(1, !top_bigger, a, b); // Move small
		}
		i++;
	}
}

void final_order(t_list **a, t_list **b)
{
	int top_bigger;
	while(ft_lst_len(*b))
	{
	if (head_position(*b) > tail_position(*b))
		top_bigger = 1;
	else
		top_bigger = 0;
	change_container(0, top_bigger, a, b);
	} 

}

void dj_buitremorales_sort(t_list **a, t_list **b)
{
	int	in_a;
	int find_bigger;
	int	last_move_pos;

	// first iteration
	in_a = 1;
	find_bigger = 1;
	last_move_pos = 1000;
	morales_movements(in_a, find_bigger, last_move_pos, a, b);
	if (is_buitripiramide(*a))
	{
		//printf("---IS BUITRIPIRAMIDE!! \n");
		//print_list(*a, *b);
		convert_2_buipiramide(a, b);
		//print_list(*a, *b);
	}
	if (ordered(*a))
	{
		//printf("ORDERED! \n");
	}
	// if is buipiramide(*b)
	final_order(a, b);


	return;


}

void order_list(t_list **a, t_list **b)
{
	int	len;

	len = ft_lst_len(*a);
	if (len == 1)
		return;
	if (len == 2)
		order_2_elements(a);
	dj_buitremorales_sort(a, b);
}

