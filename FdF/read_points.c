#include "fdf.h"

static void	append_point(float ***points, float *new_point, int *size)
{
	float	**new_array;
	int	i;

	new_array = malloc((*size + 1) * sizeof(float *));
	if (!new_array)
		return ;
	for (i = 0; i < *size; i++)
		new_array[i] = (*points)[i];
	new_array[*size] = new_point;
	free(*points);
	*points = new_array;
	(*size)++;
}

void	print_points(float **points, int n_points)
{
	for (int i = 0; i < n_points; i++)
	{
		printf("( %f, %f, %f , %f) \n", points[i][0], points[i][1], points[i][2], points[i][3]);
	}
}

void	print_points2(int **points, int n_points)
{
	for (int i = 0; i < n_points; i++)
	{
		printf("( %d, %d ) \n", points[i][0], points[i][1]);
	}
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

void	free_points2(int **points, int size)
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

float	**create_points(int fd, int *size)
{
	float		*p1;
	int		i;
	int		j;
	char	*line;
	char	**heights;
	float **points = NULL;

	*size = 0;
	line = get_next_line(fd);
	printf("line : %s \n", line);
	i = 0;
	j = 0;
	while (line)
	{
		j = 0;
		heights = ft_split(line, ' ');
		if (!heights)
			return (NULL);
		free(line);
		while (heights[j])
		{
			p1 = malloc(4 * sizeof(int));
			p1[0] = i;
			p1[1] = j;
			p1[2] = (float) ft_atoi(heights[j]);
			p1[3] = 1;
			append_point(&points, p1, size);
			free(heights[j]);
			j++;
		}
		free(heights);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	return (points);
}
