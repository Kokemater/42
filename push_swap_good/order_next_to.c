/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_next_to.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:30:02 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 12:28:40 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_to_number_min(int n, t_list *b)
{
	int		next_to_number;
	t_list	*current;

	current = b;
	next_to_number = -1;
	while (current)
	{
		if (current->position < n && (next_to_number == -1
				|| current->position > next_to_number))
			next_to_number = current->position;
		current = current->next;
	}
	if (next_to_number == -1)
		next_to_number = lst_find_max_position(b);
	return (next_to_number);
}

int	next_to_number_max(int n, t_list *b)
{
	int		next_to_number;
	t_list	*current;

	current = b;
	next_to_number = -1;
	while (current)
	{
		if (current->position > n && (next_to_number == -1
				|| current->position < next_to_number))
			next_to_number = current->position;
		current = current->next;
	}
	if (next_to_number == -1)
		next_to_number = lst_find_min_position(b);
	return (next_to_number);
}
