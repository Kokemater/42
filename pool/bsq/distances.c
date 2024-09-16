/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:23:48 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/24 11:14:44 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_obstacles(int **obstacle, int n_obstacle)
{
	int	i;

	i = 0;
	while (i < n_obstacle)
	{
		free(obstacle[i]);
		i++;
	}
	free(obstacle);
}

int	dist_to_obstacle(char **arr, int *dim, int *pos_free, char *data)
{
	int	o_i;
	int	n_obstacles;
	int	*obs_values;
	int	**obstacles;
	int	min_dist;

	obstacles = find_obstacles(arr, dim, data[1]);
	n_obstacles = num_of_obstacles(arr, dim, data[1]);
	obs_values = (int *) malloc(sizeof(int) * n_obstacles);
	if (!obs_values)
		print_error();
	o_i = 0;
	while (o_i < n_obstacles)
		set_obs_value(obstacles, &o_i, pos_free, obs_values);
	min_dist = find_min(obs_values, n_obstacles);
	free_obstacles(obstacles, n_obstacles);
	free(obs_values);
	return (min_dist);
}

int	dist_to_wall(int i, int j, int *dim)
{
	int	height;
	int	width;
	int	dist_left;
	int	dist_butt;

	height = dim[0];
	width = dim[1];
	dist_left = width - j;
	dist_butt = height - i;
	if (dist_left < dist_butt)
		return (dist_left);
	else
		return (dist_butt);
}
