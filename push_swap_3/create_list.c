/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:16:51 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/04 10:16:09 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			lst_bubble_sort(t_list *head);
static void	add_position(t_list *head);
static void	reorder_list(t_list **head, int argc, char **argv);

t_list	*create_list(int argc, char **argv)
{
	int		i;
	int		value;
	int		error;
	t_list	*head;
	t_list	*new;

	error = 0;
	head = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_a_number(argv[i]))
			return (NULL);
		value = ft_atoi_checker(argv[i], &error);
		if (error == 1)
		{
			printf("Error\n");
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

/*
This function given a linked list, return the the list ordered
and changing the position values using bubble_sort algorythm.
*/
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

	i = 1;
	while (i < argc)
	{
		correct_position = lst_find_node_by_index(*head, i - 1);
		actual_position = lst_find_node_by_value(*head, ft_atoi(argv[i]));
		lst_swap_position(head, correct_position, actual_position);
		i++;
	}
}
