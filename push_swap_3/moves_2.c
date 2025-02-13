/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:16:40 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/04 09:16:41 by jbutragu         ###   ########.fr       */
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
	printf("pb\n");
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
	printf("pa\n");
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
	printf("rra\n");
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
	printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
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

	printf("rrr\n");
}

