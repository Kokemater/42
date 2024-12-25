#include "push_swap.h"

void	sa(t_list **a)
{
	lst_swap_position(a, *a, (*a)->next);
	printf("sa\n");
}
void	sb(t_list **b)
{
	lst_swap_position(b, *b, (*b)->next);
	printf("sb\n");
}

void	ra(t_list **a)
{
	int		value;
	int		position;
	t_list	*node;

	value = (*a)->value;
	position = (*a)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_back(a, node);
	ft_remove_head(a);
	printf("ra\n");
}

void	rb(t_list **b)
{
	int		value;
	int		position;
	t_list	*node;

	value = (*b)->value;
	position = (*b)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_back(b, node);
	ft_remove_head(b);
	printf("rb\n");
}


