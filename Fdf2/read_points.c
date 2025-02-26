/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:33:59 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/26 11:00:02 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	append_point(float ***points, float *new_point, int *size)
{
	float	**new_array;
	int		i;

	i = 0;
	new_array = malloc((*size + 1) * sizeof(float *));
	if (!new_array)
		return ;
	while (i < *size)
	{
		new_array[i] = (*points)[i];
		i++;
	}
	new_array[*size] = new_point;
	free(*points);
	*points = new_array;
	(*size)++;
}

void	free_points(float **points, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(points[i]);
		i++;
	}
	free(points);
}



void	process_heights(char **heights, int *i, int *j, float ***points,
		int *size)
{
	float	*p1;

	while (heights[*j])
	{
		p1 = malloc(4 * sizeof(int));
		p1[0] = *i;
		p1[1] = *j;
		p1[2] = (float)ft_atoi(heights[*j]);
		p1[3] = 1;
		append_point(points, p1, size);
		free(heights[*j]);
		(*j)++;
	}
}

float	**create_points(int fd, int *size, int i)
{
	float	**points;
	int		j;
	char	*line;
	char	**heights;

	points = NULL;
	*size = 0;
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		heights = ft_split(line, ' ');
		if (!heights)
			return (free(line), NULL);
		free(line);
		process_heights(heights, &i, &j, &points, size);
		free(heights);
		i++;
		line = get_next_line(fd);
	}
	return (free(line), points);
}
