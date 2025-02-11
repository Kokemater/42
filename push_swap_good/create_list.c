/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:16:51 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 01:26:30 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int			lst_bubble_sort(t_list *head);
static void	add_position(t_list *head);
static void	reorder_list(t_list **head, int argc, char **argv);

t_list	*create_list(int argc, char **argv)
{
	int		i;
	long	value;
	t_list	*head;
	t_list	*new;

	head = NULL;
	i = 0;
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		if (value - 1 == MAX_INT)
		{
			write(1, "Error\n", 6);
			return (NULL);
		}
		new = ft_lstnew(value, 0);
		i++;
		ft_lstadd_back(&head, new);
	}
	if (lst_bubble_sort(head))
		return (NULL);
	add_position(head);
	reorder_list(&head, argc, argv);
	return (head);
}

void	bubble_swap(t_list *tmp, t_list *tmp_next, int *ordered)
{
	int	temp_data;

	if (tmp_next->value < tmp->value)
	{
		*ordered = 0;
		temp_data = tmp_next->value;
		tmp_next->value = tmp->value;
		tmp->value = temp_data;
	}
}

int	lst_bubble_sort(t_list *head)
{
	t_list	*tmp;
	t_list	*tmp_next;
	int		ordered;

	if (!(head))
		return (1);
	tmp = head;
	tmp_next = head->next;
	ordered = 0;
	while (!ordered)
	{
		ordered = 1;
		while (tmp_next != NULL)
		{
			bubble_swap(tmp, tmp_next, &ordered);
			if (tmp_next->value == tmp->value)
				return (1);
			tmp = tmp_next;
			tmp_next = tmp_next->next;
		}
		tmp = head;
		tmp_next = tmp->next;
	}
	return (0);
}

static void	add_position(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head->position = i;
		head = head->next;
		i++;
	}
}

static void	reorder_list(t_list **head, int argc, char **argv)
{
	int		i;
	t_list	*correct_position;
	t_list	*actual_position;

	i = 0;
	while (i < argc)
	{
		correct_position = lst_find_node_by_index(*head, i);
		actual_position = lst_find_node_by_value(*head, ft_atoi(argv[i]));
		lst_swap_position(head, correct_position, actual_position);
		i++;
	}
}
