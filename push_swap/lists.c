#include "push_swap.h"

t_list  *ft_lstlast(t_list *lst)
{
        if (lst == NULL)
                return (NULL);
        while (lst->next != NULL)
        {
                lst = lst->next;
        }
        return (lst);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
        t_list  *last_node;

        if (!lst || !new)
                return ;
        if (*lst == NULL)
			*lst = new;
		else
		{
			last_node = ft_lstlast(*lst);
			last_node->next = new;
		}
}

t_list  *ft_lstnew(int value, int position)
{
        t_list  *new_node;

        new_node = (t_list *) malloc(sizeof(t_list));
        if (!new_node)
                return (NULL);
        new_node->position = position;
		new_node->value = value;
        new_node->next = NULL;
        return (new_node);
}

void	print_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	while(temp != NULL)
	{
		printf("NODE: val = %d, pos = %d \n", temp->value, temp->position);
		temp = temp->next;
	}
	return ;
}