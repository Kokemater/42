/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:43:09 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 12:50:53 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **inputs)
{
	int	i;

	i = 0;
	if (!inputs)
		return ;
	while (inputs[i])
	{
		free(inputs[i]);
		i++;
	}
	free(inputs);
}
