/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:28:53 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/10 16:26:10 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **a, t_list** b)
{
	int		value;
	int		position;
	t_list	*node;

	value = (*a)->value;
	position = (*a)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_front(b, node);
	ft_remove_head(a);
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list** b)
{
	int		value;
	int		position;
	t_list	*node;

	value = (*b)->value;
	position = (*b)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_front(a, node);
	ft_remove_head(b);
	write(1, "pa\n", 3);
}

void	rra(t_list **a)
{
	int		value;
	int		position;
	t_list	*node;
	t_list	*last_node;

	last_node = ft_lstlast(*a);
	value = (last_node)->value;
	position = (last_node)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_front(a, node);
	ft_remove_tail(a);
	write(1, "rra\n", 4);
}


void	rrb(t_list **b)
{
	int		value;
	int		position;
	t_list	*node;
	t_list	*last_node;

	last_node = ft_lstlast(*b);
	value = (last_node)->value;
	position = (last_node)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_front(b, node);
	ft_remove_tail(b);
	write(1, "rrb\n", 4);
}

void rrr(t_list **a, t_list **b)
{
	int		value;
	int		position;
	t_list	*node;
	t_list	*last_node;

	last_node = ft_lstlast(*a);
	value = (last_node)->value;
	position = (last_node)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_front(a, node);
	ft_remove_tail(a);
	last_node = ft_lstlast(*b);
	value = (last_node)->value;
	position = (last_node)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_front(b, node);
	ft_remove_tail(b);

	write(1, "rrr\n", 4);
}

