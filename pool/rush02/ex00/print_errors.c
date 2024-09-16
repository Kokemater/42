/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvera-ve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:13:57 by jvera-ve          #+#    #+#             */
/*   Updated: 2024/07/20 11:19:32 by jvera-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_dict_error(void)
{
	write(1, "Dict Error\n", 11);
}

void	print_flag(void)
{
	write(1, "FLAGG\n", 6);
}
