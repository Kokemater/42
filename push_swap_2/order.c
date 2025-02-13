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

int is_ceros(int index, int digits, t_list *a)
{
	char	*binary;

	while(a)
	{
		binary = ft_itoa_binary_len(a->position, digits);
		//printf("text : %s , index = %d \n", binary, index);
		if (binary[index] == '0')
			return (free(binary), 1);
		free(binary);
		a = a->next;
	}
	//printf("NO CEROS");
	return (0);
}

int	is_ordered_by_binary_index(int index, int digits, t_list *a)
{
	char	*binary;
	int		current_number;
	int		previous_number;
	
	previous_number = -1;
	while(a)
	{
		binary = ft_itoa_binary_len(a->position, digits);
		if (!binary)
			return (-1); // consider this case later
		current_number = ft_atoi_binary(binary + index);
		free(binary);
		if (current_number < previous_number)
			return (0);
		previous_number = current_number;
		a = a->next;
	}
	return (1);
}

void order_list(t_list **a, t_list **b)
{
	int	len;
	int	i;
	len = ft_lst_len(*a);
	if (len == 1)
		return;
	if (len == 2)
		order_2_elements(a);

	int		digits;
	char	*head;
	int		index;
	int		n_rotations;
	digits = n_binary_digits(len - 1);
	index = digits -1;
	// A to B
	////print_listt(*a, *b);
	while(index >= 0 && !is_ordered(*a))
	{
		i = 0;
		n_rotations = 0;
		while(i < len && !(is_ordered_by_binary_index(index, digits, *a)))
		{
			head = ft_itoa_binary_len(head_position(*a), digits);
			if (!head)
				return ;
			//printf("head: %s \n", head);
			if (head[index] == '0')
				pb(a,b);
			else
			{
				ra(a);
				n_rotations++;
			}
			i++;
			free(head);
			print_list(*a, *b);
		}
		// Merge
		while(ft_lst_len(*b))
		{
			pa(a,b);
		}
		print_list(*a, *b);
		index--;
	}

}

