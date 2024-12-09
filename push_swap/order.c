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


void order_list(t_list **head)
{
	int	len;

	len = ft_lst_len(*head);

	if (len == 1)
		return;
	if (len == 2)
		order_2_elements(head);
	return ;
}