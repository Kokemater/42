/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:29:44 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/10 17:29:01 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		errors;

	errors = inspect_errors(argc, argv);
	if (errors)
		return (0);
	a = create_list(argc, argv);
	if (!a) // return 1 - negativos - ordenar - comillas - maxmin int -
		return (1);
	b = NULL;
	order_list(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
}
