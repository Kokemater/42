#include "push_swap.h"

void	change_container(int in_a, int in_top, t_list **a, t_list **b)
{
	if (in_a && in_top)
	{
		pb(a,b);
	}
	else if (in_a && !in_top)
	{
		rra(a);
		pb(a,b);
	}
	else if(!in_a && in_top)
	{
		pa(a,b);
	}
	else if (!in_a && !in_top)
	{
		rrb(b);
		pa(a,b);
	}
}