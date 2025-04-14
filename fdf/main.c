/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:21:32 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/02 15:01:05 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	**read_arguments(int argc, char **argv, int *size)
{
	int	fd;
	int	i;

	i = 0;
	if (argc != 2)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (NULL);
	}
	return (create_points(fd, size, i));
}

float	**transform_points(float **world_points,
		int size)
{
	float	x;
	float	y;
	float	z;
	float	**screen_points;
	int		i;

	i = 0;
	screen_points = (float **)malloc(sizeof(float *) * size);
	if (!screen_points)
		return (NULL);
	while (i < size)
	{
		x = world_points[i][0];
		y = world_points[i][1];
		z = world_points[i][2];
		screen_points[i] = (float *) malloc(sizeof(float) * 2);
		if (!screen_points[i])
			return (NULL);
		screen_points[i][0] = -(x - y) * SCALE * (1 + 250.0 / size) + WIDTH / 2;
		screen_points[i][1] = (x + y) * SCALE * (1 + 250.0 / size) / 2;
		screen_points[i][1] += -z * SCALE * (1 + 250.0 / size) + HEIGHT / 2;
		i++;
	}
	return (screen_points);
}




int	main(int argc, char **argv)
{
	t_data	data;

	data.w_points = read_arguments(argc, argv, &(data.size));
	if (!data.w_points)
		return (1);
	data.s_points = transform_points(data.w_points, data.size);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF - MiniLibX");
	if (!data.win)
		return (1);
	create_image(data.mlx, &data.img, WIDTH, HEIGHT);
	put_points(data, data.s_points, data.size, data.w_points);
	connect_points_using_dda(data, data.s_points, data.w_points, data.size);
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
