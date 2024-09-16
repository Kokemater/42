/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvera-ve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:37:00 by jvera-ve          #+#    #+#             */
/*   Updated: 2024/07/20 11:55:30 by jvera-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **args)
{
	int	check_error;

	if (argc == 2)
	{
		check_error = atoi_english(args[1]);
		if (check_error == -1)
			return (1);
		return (0);
	}
	// if (argc == 3)
	// {
	// 	check_error = input_dict(args[1], args[2]);
	// 	if (check_error == -1)
	// 		return (1);
	// 	return (0);
	// }
	print_error();
	return (1);
}

