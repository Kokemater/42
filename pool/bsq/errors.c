/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:15:47 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/24 11:06:21 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
int	check_errors(char *text)
{
	int	i;
	int	num_i;
	i = skip_the_first_line(text);
	num_i = 0;
	while(text[num_i] >= '0' && text[num_i] <= '9')
		num_i++;

	if (i - num_i !=2 )
		return (-1);
	return (0);
}

char	*print_error(void)
{
	write(1, "Error", 6);
	exit(1);
}
