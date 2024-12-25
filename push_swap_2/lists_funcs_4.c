#include "push_swap.h"

int	head_position(t_list *list)
{
	int position;

	if (!list)
		return (-1);
	position = list->position;
	return (position);
}

int	tail_position(t_list *list)
{
	int	position;

	if (!list)
		return (-1);
	list = ft_lstlast(list);
	position = list->position;
	return (position);
}