/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:54:16 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 13:30:49 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				position;
	int				value;
	struct s_list	*next;
}					t_list;

# define MAX_INT 2147483647
# define MIN_INT -2147483648

// general use funcs
long				ft_atol(const char *str);
int					ft_atoi(const char *str);
int					ft_atoi_checker(const char *str, int *error);
char				*ft_itoa_binary_len(int n, int len);
int					is_a_number(const char *str);
float				ft_abs(float x);
float				ft_min(float a, float b);
float				ft_max(float a, float b);
float				ft_min3(float a, float b, float c);
int					inspect_errors(int argc, char **argv);
int					ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**join_arrays(char **arr1, char **arr2);
char				**join_args(int argc, char **argv, int *total_len);
void				free_arr(char **inputs);
char				**ft_split_spaces(const char *s);
int					count_words(const char *s, char c);
// lst funcs
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(int value, int position);
void				ft_lstclear(t_list **lst);
int					ft_lst_len(t_list *head);
t_list				*create_list(int argc, char **argv);
void				lst_swap_position(t_list **head, t_list *node_a,
						t_list *node_b);
t_list				*lst_find_node_by_index(t_list *head, int index);
t_list				*lst_find_node_by_value(t_list *head, int value);
t_list				*lst_prev_node(t_list *head, t_list *node);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_remove_head(t_list **lst);
void				ft_remove_tail(t_list **lst);
int					head_position(t_list *list);
int					tail_position(t_list *list);
int					lst_find_max_position(t_list *head);
int					lst_find_min_position(t_list *head);
int					lst_find_index_by_position(t_list *head, int position);
// movements
void				sa(t_list **a);
void				ra(t_list **a);
void				rb(t_list **b);
void				pb(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				rra(t_list **a);
void				rrb(t_list **a);
void				rr(t_list **a, t_list **b);
void				rrr(t_list **a, t_list **b);

// Order
void				order_list(t_list **a, t_list **b);
void				apply_best_move(int *i, t_list **a, t_list **b,
						int pa);
void				order_2_elements(t_list **a);
void				order_3_elements(t_list **a);
int					next_to_number_min(int n, t_list *b);
int					next_to_number_max(int n, t_list *b);
void				place_element_in_top_a(int i_a, int n_a, t_list **a,
						int *a_moves);
void				place_element_in_top_b(int i_a, int n_a, t_list **a,
						int *b_moves);
void				apply_moves_paralel_up(int a_pos, int b_pos, t_list **a,
						t_list **b);
void				apply_moves_paralel_down(int a_pos, int b_pos, t_list **a,
						t_list **b);
void				apply_moves_no_paralel_a(int a_position, int i_a,
						t_list **a, int *n);
void				apply_moves_no_paralel_b(int b_position, int i_b,
						t_list **b, int *n);
void				push(int push_to_a, t_list **a, t_list **b);
int					moves_no_paralel(int i_a, int i_b, int n_a, int n_b);
int					moves_paralel_down(int steps_down_a, int steps_down_b);
int					moves_paralel_up(int i_a, int i_b);
int					n_moves(int i_a, int n_a, int current_position, t_list **b,
						int *i_b);
int					n_moves2(int i_a, int n_a, int current_position, t_list **b,
						int *i_b);

#endif