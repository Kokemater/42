/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:15:47 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/24 12:40:57 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	is_free(char **array, int i, int j, char free)
{
	if (array[i][j] == free)
		return (1);
	return (0);
}

int	is_obstacle(char **array, int i, int j, char obstacle)
{
	if (array[i][j] == obstacle)
		return (1);
	return (0);
}

int	num_of_obstacles(char **arr, int *dim, char obs_letter)
{
	int	i;
	int	j;
	int	num_of_obstacle;

	num_of_obstacle = 0;
	i = 0;
	while (i < dim[0])
	{
		j = 0;
		while (j < dim[1])
		{
			if (is_obstacle(arr, i, j, obs_letter))
			{
				num_of_obstacle++;
			}
			j++;
		}
		i++;
	}
	return (num_of_obstacle);
}

void	add_obstacle(int **obstacle, int pos, int i, int j)
{
	obstacle[pos] = malloc(sizeof(int) * 2);
	if (!obstacle[pos])
		print_error();
	obstacle[pos][0] = i;
	obstacle[pos][1] = j;
}

int	**find_obstacles(char **arr, int *dim, char obs_letter)
{
	int	i;
	int	j;
	int	pos;
	int	num_obstacles;
	int	**obstacle;

	num_obstacles = num_of_obstacles(arr, dim, obs_letter);
	obstacle = (int **) malloc(sizeof(int *) * num_obstacles);
	i = 0;
	pos = 0;
	while (i < dim[0])
	{
		j = 0;
		while (j < dim[1])
		{
			if (is_obstacle(arr, i, j, obs_letter))
			{
				add_obstacle(obstacle, pos, i, j);
				pos++;
			}
			j++;
		}
		i++;
	}
	return (obstacle);
}
