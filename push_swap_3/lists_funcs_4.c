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

int	lst_find_max_position(t_list *head)
{
	int max_position = -1;

	while(head)
	{
		if (head->position > max_position)
			max_position = head->position;
		head = head->next;
	}
	return (max_position);
}


int	lst_find_min_position(t_list *head)
{
	int min_position = 100000; 

	while(head)
	{
		if (head->position < min_position)
			min_position = head->position;
		head = head->next;
	}
	return (min_position);
}

int	lst_find_index_by_position(t_list *head, int position)
{
	int	index;

	index = 0;
	while (head)
	{
		if (position == head->position)
			return (index);
		head = head->next;
		index++;
	}
	return (-1);	
}