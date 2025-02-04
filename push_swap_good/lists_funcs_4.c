/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funcs_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:22:39 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/04 10:27:21 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	head_position(t_list *list)
{
	int	position;

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
	int	max_position;

	max_position = -1;
	while (head)
	{
		if (head->position > max_position)
			max_position = head->position;
		head = head->next;
	}
	return (max_position);
}


int	lst_find_min_position(t_list *head)
{
	int	min_position;

	min_position = 100000;
	while (head)
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
