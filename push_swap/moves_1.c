/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:28:47 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/10 17:08:11 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	lst_swap_position(a, *a, (*a)->next);
	write(1, "sa\n", 3);
}

void	ra(t_list **a)
{
	int		value;
	int		position;
	t_list	*node;

	value = (*a)->value;
	position = (*a)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_back(a, node);
	ft_remove_head(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	int		value;
	int		position;
	t_list	*node;

	value = (*b)->value;
	position = (*b)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_back(b, node);
	ft_remove_head(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	int		value;
	int		position;
	t_list	*node;

	value = (*a)->value;
	position = (*a)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_back(a, node);
	ft_remove_head(a);
	value = (*b)->value;
	position = (*b)->position;
	node = ft_lstnew(value, position);
	ft_lstadd_back(b, node);
	ft_remove_head(b);
	write(1, "rr\n", 3);
}
