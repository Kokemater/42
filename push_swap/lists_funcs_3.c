/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funcs_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:21:35 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 13:58:47 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		new->next = (*lst);
		*lst = new;
	}
}

void	ft_remove_head(t_list **lst)
{
	t_list	*new_head;
	t_list	*head;

	head = *lst;
	if (!head)
		return ;
	new_head = (*lst)->next;
	free(head);
	*lst = new_head;
}

void	ft_remove_tail(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (!tmp)
		return ;
	else if (!(tmp->next))
	{
		free(tmp);
		*lst = NULL;
		return ;
	}
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

t_list	*lst_find_node_by_value(t_list *head, int value)
{
	while (head != NULL)
	{
		if (head->value == value)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int	ft_lst_len(t_list *head)
{
	int	len;

	len = 0;
	while (head != NULL)
	{
		head = head->next;
		len++;
	}
	return (len);
}
