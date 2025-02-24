#include "fdf.h"

float	**read_arguments(int argc, char **argv, int *size)
{
	int	fd;

	if (argc != 2)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (NULL);
	}
	return (create_points(fd, size));
}

float	**transform_points(float **world_points, int width, int height,
		int size)
{
	float	x;
	float	y;
	float	z;
	float	**screen_points;

	screen_points = (float **)malloc(sizeof(float *) * size);
	if (!screen_points)
		return (NULL);
	for (int i = 0; i < size; i++)
	{
		x = world_points[i][0];
		y = world_points[i][1];
		z = world_points[i][2];
		screen_points[i] = (float *)malloc(sizeof(float) * 2);
		if (!screen_points[i])
			return (NULL);
		screen_points[i][0] = -(x - y) * SCALE + width / 2;
		screen_points[i][1] = (x + y) * SCALE / 2 - z * SCALE + height / 2;
	}
	return (screen_points);
}

void	draw_line_dda(void *mlx, void *win, float *p1, float *p2)
{
	float	dx;
	float	dy;
	int		steps;
	float	current[2];
	int i = 0;

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
		if (current[0] >= 0 && current[0] < WIDTH && current[1] >= 0 && current[1] < HEIGHT)
			mlx_pixel_put(mlx, win, (int) current[0], (int)current[1], 0xFFFFFF);
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
	for (int i = 0; i < size; i++)
	{
		if (screen_points[i][0] >= 0 && screen_points[i][0] < WIDTH
			&& screen_points[i][1] >= 0 && screen_points[i][1] < HEIGHT)
		{
			mlx_pixel_put(data.mlx, data.win, (int)screen_points[i][0],
				(int)screen_points[i][1], 0xFFFFFF);
		}
	}
}
int	main(int argc, char **argv)
{
	t_data	data;
	int		size;

	float **world_points;  // Array of points (x , y ,z, w) in world coordinates
	float **screen_points; // Array of points (x ,y) in screen coordinates
	world_points = read_arguments(argc, argv, &size);
	if (!world_points)
		return (1);
	screen_points = transform_points(world_points, WIDTH, HEIGHT, size);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF - MiniLibX");
	if (!data.win)
		return (1);
	put_points(data, screen_points, size);
	connect_points_using_dda(data, screen_points, world_points, size);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	free_points(world_points, size);
	free(screen_points);
	return (0);
}
