/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:29:44 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 12:49:04 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		errors;
	char	**inputs;
	int		input_len;

	if (argc == 1)
		return (0);
	inputs = join_args(argc, argv, &input_len);
	errors = inspect_errors(input_len, inputs);
	if (errors)
		return (free_arr(inputs), 1);
	a = create_list(input_len, inputs);
	if (!a)
		return (free_arr(inputs), ft_lstclear(&a), 1);
	b = NULL;
	order_list(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	free_arr(inputs);
}
