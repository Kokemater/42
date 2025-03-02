/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:33:59 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/02 12:23:27 by jbutragu         ###   ########.fr       */
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

static void	free_all(char **heights_and_color, int len)
{
	while (len >= 0)
		free(heights_and_color[len--]);
	free(heights_and_color);
}

void	process_heights(char **data, int i, float ***points,
	int *size)
{
	float	*p1;
	char	**heights_and_color;
	int		len;
	int		j;

	j = 0;
	while (data[j])
	{
		heights_and_color = ft_split(data[j], ',');
		len = 0;
		while (heights_and_color[len])
			len++;
		p1 = malloc(5 * sizeof(int));
		p1[0] = i;
		p1[1] = j;
		p1[2] = (float) ft_atoi(heights_and_color[0]);
		p1[3] = 1;
		if (len == 1)
			p1[4] = (float) 0xFFFFFF;
		else
			p1[4] = (float) atoi_hexadecimal(heights_and_color[1]);
		append_point(points, p1, size);
		free(data[j++]);
		free_all(heights_and_color, len);
	}
}

float	**create_points(int fd, int *size, int i)
{
	float	**points;
	char	*line;
	char	**heights;

	points = NULL;
	*size = 0;
	line = get_next_line(fd);
	while (line)
	{
		heights = ft_split(line, ' ');
		if (!heights)
			return (free(line), NULL);
		free(line);
		process_heights(heights, i, &points, size);
		free(heights);
		i++;
		line = get_next_line(fd);
	}
	return (free(line), points);
}
