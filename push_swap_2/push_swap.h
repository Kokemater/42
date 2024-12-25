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

//general use funcs
int		ft_atoi(const char *str);
int n_binary_digits(int n);
char	*ft_itoa_binary_len(int n, int len);
int		is_a_number(const char *str);
int		ft_atoi_binary(char *binary_number);

// lst funcs
void    ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_lstnew(int value, int position);
void	print_list(t_list *a, t_list *b);
void	ft_lstclear(t_list **lst);
int		ft_lst_len(t_list *head);
t_list	*create_list(int argc, char **argv);
void	lst_swap_position(t_list **head, t_list *node_a, t_list *node_b);
t_list	*lst_find_node_by_index(t_list *head, int index);
t_list	*lst_find_node_by_value(t_list *head, int value);
t_list	*lst_prev_node(t_list *head, t_list *node);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_remove_head(t_list **lst);
void	ft_remove_tail(t_list **lst);
int	head_position(t_list *list);
int	tail_position(t_list *list);

// Order funcs
void	order_list(t_list **a, t_list **b);

// movements
void	sa(t_list **a);
void	sb(t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	pb(t_list **a, t_list** b);
void	pa(t_list **a, t_list** b);
void	rra(t_list **a);
void	rrb(t_list **a);
void	change_container(int in_a, int in_top, t_list **a, t_list **b);

#endif