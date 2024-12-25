/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:22:58 by jbutragu          #+#    #+#             */
/*   Updated: 2024/10/07 17:22:58 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt;
	t_list	*current;

	current = *lst;
	while (current != NULL)
	{
		nxt = current->next;
		del(current->content);
		free(current);
		current = nxt;
	}
	*lst = NULL;
}
