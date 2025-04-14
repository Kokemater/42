/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funcs_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:17:37 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 17:52:22 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_find_node_by_index(t_list *head, int index)
{
	int	i;

	i = 0;
	while (i < index && head != NULL)
	{
		head = head->next;
		i++;
	}
	return (head);
}

t_list	*lst_prev_node(t_list *head, t_list *node)
{
	if (head == node)
		return (NULL);
	while (head)
	{
		if (head->next == node)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static void	swap_consecutive_nodes(t_list **head, t_list *a, t_list *b,
		t_list *prev)
{
	if (a->next == b)
	{
		if (prev)
			prev->next = b;
		else
			*head = b;
		a->next = b->next;
		b->next = a;
	}
	else if (b->next == a)
	{
		if (prev)
			prev->next = a;
		else
			*head = a;
		b->next = a->next;
		a->next = b;
	}
}

static void	update_nodes(t_list *node_a, t_list *node_b)
{
	t_list	*temp;

	temp = node_a->next;
	node_a->next = node_b->next;
	node_b->next = temp;
}

void	lst_swap_position(t_list **head, t_list *node_a, t_list *node_b)
{
	t_list	*prev;
	t_list	*node_a_prev;
	t_list	*node_b_prev;

	if (node_a->next == node_b || node_b->next == node_a)
	{
		prev = lst_prev_node(*head, node_a);
		if (node_b->next == node_a)
			prev = lst_prev_node(*head, node_b);
		swap_consecutive_nodes(head, node_a, node_b, prev);
		return ;
	}
	node_a_prev = lst_prev_node(*head, node_a);
	node_b_prev = lst_prev_node(*head, node_b);
	if (node_a_prev)
		node_a_prev->next = node_b;
	else
		*head = node_b;
	if (node_b_prev)
		node_b_prev->next = node_a;
	else
		*head = node_a;
	update_nodes(node_a, node_b);
}
