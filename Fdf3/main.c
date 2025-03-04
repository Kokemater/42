/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:21:32 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/27 12:38:53 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*read_arguments(int argc, char **argv, int *size)
{
	int	fd;
	int i;
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

float	**transform_points(float **world_points, int width, int height,
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
		screen_points[i] = (float *)malloc(sizeof(float) * 2);
		if (!screen_points[i])
			return (NULL);
		screen_points[i][0] = -(x - y) * SCALE + width / 2;
		screen_points[i][1] = (x + y) * SCALE / 2 - z * SCALE + height / 2;
		i++;
	}
	return (screen_points);
}

void imprimir_nodos(t_list *head) {
	t_list *nodo = head;
	while(nodo)
	{
    if (!nodo || !nodo->content)
        return;

    float *valores = (float *)nodo->content;
    printf("Valores: [%.2f, %.2f, %.2f, %.2f]\n", valores[0], valores[1], valores[2], valores[3]);
	nodo = nodo->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		size;
	t_list *world_points;
	float	**screen_points;

	world_points = NULL;
	world_points = read_arguments(argc, argv, &size);

	if (!world_points)
		return (1);
	//screen_points = transform_points(world_points, WIDTH, HEIGHT, size);
	// data.mlx = mlx_init();
	// if (!data.mlx)
	// 	return (1);
	// data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF - MiniLibX");
	// if (!data.win)
	// 	return (1);
	// put_points(data, screen_points, size, world_points);
	// connect_points_using_dda(data, screen_points, world_points, size);
	// mlx_key_hook(data.win, key_press, &data);
	// mlx_hook(data.win, 17, 0, close_window, &data);
	// mlx_loop(data.mlx);
	ft_lstclear(&world_points, free);
	free(screen_points);
	return (0);
}
