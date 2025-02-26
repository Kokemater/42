/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:33:03 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/26 10:33:05 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_dda(void *mlx, void *win, float *p1, float *p2)
{
	float	dx;
	float	dy;
	int		steps;
	float	current[2];
	int		i;

	i = 0;
	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	current[0] = p1[0];
	current[1] = p1[1];
	while (i < steps)
	{
		if (current[0] >= 0 && current[0] < WIDTH && current[1] >= 0
			&& current[1] < HEIGHT)
			mlx_pixel_put(mlx, win, (int)current[0], (int)current[1], 0xFFFFFF);
		current[0] += dx / steps;
		current[1] += dy / steps;
		i++;
	}
}

void	connect_points_using_dda(t_data data, float **screen_points,
		float **world_points, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((world_points[i][0] == world_points[j][0]
					&& world_points[i][1] == world_points[j][1] + 1)
				|| (world_points[i][1] == world_points[j][1]
					&& world_points[i][0] == world_points[j][0] + 1))
			{
				draw_line_dda(data.mlx, data.win, screen_points[i],
					screen_points[j]);
			}
			j++;
		}
		i++;
	}
}

void	put_points(t_data data, float **screen_points, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (screen_points[i][0] >= 0 && screen_points[i][0] < WIDTH
			&& screen_points[i][1] >= 0 && screen_points[i][1] < HEIGHT)
		{
			mlx_pixel_put(data.mlx, data.win, (int)screen_points[i][0],
				(int)screen_points[i][1], 0xFFFFFF);
		}
		i++;
	}
}
