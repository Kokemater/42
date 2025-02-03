#include "push_swap.h"

void	order_2_elements(t_list **a)
{
	if ((*a)->next->position < (*a)->position)
		ra(a);
}

void	order_3_elements(t_list **a)
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