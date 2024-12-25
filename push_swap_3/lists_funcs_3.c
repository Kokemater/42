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
	else if (!(tmp ->next))
	{
		free(tmp);
		*lst = NULL;
		return ;
	}
	while(tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}