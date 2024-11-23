#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
        int position;
		int value;
        struct s_list   *next;
}       t_list;

int	ft_atoi(const char *str);
int	is_a_number(const char *str);


void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_lstnew(int value, int position);
void	print_list(t_list *head);


t_list	*create_list(int argc, char **argv);



#endif