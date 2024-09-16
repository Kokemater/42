/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:23:48 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/24 12:39:04 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	set_obs_value(int **obstacles, int *o_i, int *pos_free, int *obs_values)
{
	int	pos;

	pos = 0;
	obs_values[*o_i] = 0;
	while (pos < 2)
	{
		if ((obstacles[*o_i][0] - pos_free[0] < 0)
				|| (obstacles[*o_i][1] - pos_free[1] < 0))
			break ;
		if (obstacles[*o_i][pos] - pos_free[pos] > obs_values[*o_i])
			obs_values[*o_i] = obstacles[*o_i][pos] - pos_free[pos];
		pos++;
	}
	(*o_i)++;
}

int	*change_answer(int size, int i, int j, int *biggest_square)
{
	biggest_square[0] = size;
	biggest_square[1] = i;
	biggest_square[2] = j;
	return (biggest_square);
}

int	*initialize_answer(void)
{
	int	*biggest_square;

	biggest_square = (int *) malloc(sizeof(int) * 3);
	if (!biggest_square)
		print_error();
	biggest_square[0] = -1;
	biggest_square[1] = -1;
	biggest_square[2] = -1;
	return (biggest_square);
}

void	max_sq_allowed(int *dim, int *biggest_square, int number, int *pos_free)
{
	int	i;
	int	j;

	i = pos_free[0];
	j = pos_free[1];
	if (dist_to_wall(i, j, dim) < number || number == 0)
		number = dist_to_wall(i, j, dim);
	if (number > biggest_square[0])
		change_answer(number, i, j, biggest_square);
}

int	*find_biggest_square(char **arr, int *dim, char *data)
{
	int	i;
	int	j;
	int	number;
	int	pos_free[2];
	int	*biggest_square;

	biggest_square = initialize_answer();
	i = 0;
	while (i < dim[0])
	{
		j = 0;
		while (j < dim[1])
		{
			if (is_free(arr, i, j, data[0]))
			{
				pos_free[0] = i;
				pos_free[1] = j;
				number = dist_to_obstacle(arr, dim, pos_free, data);
				max_sq_allowed(dim, biggest_square, number, pos_free);
			}
			j++;
		}
		i++;
	}
	return (biggest_square);
}
