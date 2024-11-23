#include "push_swap.h"

int lst_bubble_sort(t_list *head);
static void	add_position(t_list *head);
static void reorder_list(t_list **head, int argc,char **argv);

t_list	*create_list(int argc, char **argv)
{
	int		i;
	int		value;
	t_list  *head;
	t_list	*new;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_a_number(argv[i]))
			return (NULL);
		value = ft_atoi(argv[i]);
		new = ft_lstnew(value, 0);
		i++;
		ft_lstadd_back(&head, new);
	}
	if (lst_bubble_sort(head))
		return (NULL);
	add_position(head);
	reorder_list(&head,argc, argv);
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
	while(!ordered)
	{
		ordered = 1;
		while(tmp_next != NULL)
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
	int i;

	i = 0;
	while(head)
	{
		head->position = i;
		head = head->next;
		i++;
	}
}

t_list	*lst_find_node_by_index(t_list *head, int index)
{
	int i;

	i = 0;
	while(i < index && head != NULL)
	{
		head = head->next;
		i++;
	}
	return (head);
}

t_list	*lst_find_node_by_value(t_list *head, int value)
{
	int i;

	i = 0;
	while(head != NULL)
	{
		if (head->value == value)
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_list	*lst_prev_node(t_list *head, t_list *node)
{
	if (head == node)
		return (NULL);
	while(head)
	{
		if (head->next == node)
			return (head);
		head = head->next;
	}
	return (NULL);
}
void swap_consecutive_nodes(t_list **head, t_list *a, t_list *b, t_list *a_prev, t_list *b_prev)
{
	if (a->next == b)
	{
		if (a_prev)
			a_prev->next = b;
		else
			*head = b;
		a->next = b->next;
		b->next = a;
		return;
    }
	else if (b->next == a)
	{
        if (b_prev)
            b_prev->next = a;
        else
            *head = a;
        b->next = a->next;
        a->next = b;
        return;
    }
}

void lst_swap_position(t_list **head, t_list *node_a, t_list *node_b)
{
    t_list	*node_a_prev;
    t_list	*node_b_prev;
	t_list	*temp;

	node_a_prev = lst_prev_node(*head, node_a);
	node_b_prev = lst_prev_node(*head, node_b);
	if (node_a->next == node_b || node_b->next == node_a)
	{
		swap_consecutive_nodes(head, node_a, node_b, node_a_prev, node_b_prev);
		return ;
	}
    if (node_a_prev)
        node_a_prev->next = node_b;
    else
        *head = node_b;
    if (node_b_prev)
        node_b_prev->next = node_a;
    else
        *head = node_a;
    temp = node_a->next;
    node_a->next = node_b->next;
    node_b->next = temp;
}



static void reorder_list(t_list **head, int argc,char **argv)
{
	int		i;
	t_list	*correct_position;
	t_list	*actual_position;

	i = 1;
	while(i < argc)
	{
		correct_position = lst_find_node_by_index(*head, i - 1);
		actual_position = lst_find_node_by_value(*head, ft_atoi(argv[i]));
		lst_swap_position(head, correct_position, actual_position);
		i++;
	}
}
