#include "fdf.h"

int	ft_atoi_hexadecimal(const char *hex)
{
	int		result;
	int		i;
	char	c;
		int digit;

	result = 0;
	i = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
	{
		i = 2;
	}
	// Recorremos cada caracter de la cadena hexadecimal
	for (; hex[i] != '\0'; i++)
	{
		c = hex[i];
		// Convertir el caracter a un valor numérico
		if (c >= '0' && c <= '9')
		{
			digit = c - '0'; // Convertir '0'-'9' a 0-9
		}
		else if (c >= 'a' && c <= 'f')
		{
			digit = c - 'a' + 10; // Convertir 'a'-'f' a 10-15
		}
		else if (c >= 'A' && c <= 'F')
		{
			digit = c - 'A' + 10; // Convertir 'A'-'F' a 10-15
		}
		else
		{
			
			return (-1);
		}
		// Actualizar el valor acumulado en base 16
		result = result * 16 + digit;
	}
	return (result);
}

static void	append_point(float ***points, float *new_point, int *size)
{
	float	**new_array;
	int		i;

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

float	**create_points(int fd, int *size)
{
	float	*p1;
	int		i;
	int		j;
	char	*line;
	char	**heights;
	float	**points;

	points = NULL;
	*size = 0;
	line = get_next_line(fd);
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
			if (heights[j][0] == '0' && heights[j][1] == 'x')
				p1[2] = (float) ft_atoi_hexadecimal(heights[j]);
			else
				p1[2] = (float)ft_atoi(heights[j]);
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
