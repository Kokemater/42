#include "fdf.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 800
#define HEIGHT 600

// Función para leer los puntos desde un archivo
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
		// Suponiendo que `create_points` esté implementada
}

// Función para crear la matriz de vista
float	*set_view_matrix(void)
{
	float	*view_matrix;

	view_matrix = malloc(sizeof(float) * 16);
	for (int i = 0; i < 16; i++)
	{
		view_matrix[i] = 0;
	}
	view_matrix[0] = 1;
	view_matrix[5] = 1;
	view_matrix[10] = 1;
	view_matrix[14] = -1;
	view_matrix[15] = 1;
	return (view_matrix);
}

// Función para crear la matriz de proyección ortográfica
float *ortho_projection_matrix() {
    float *proy_matrix = malloc(sizeof(float) * 16);
    for (int i = 0; i < 16; i++) {
        proy_matrix[i] = 0;
    }
    proy_matrix[0] = 1.0f;  // Sin escala en x
    proy_matrix[5] = 1.0f;  // Sin escala en y
    proy_matrix[10] = 1.0f; // Sin cambio en z
    proy_matrix[15] = 1.0f; // w = 1
    return proy_matrix;
}


// Función para crear la matriz de proyección
float	*set_projection_matrix(void)
{
	return (ortho_projection_matrix());
}

// Función para transformar los puntos 3D a coordenadas 2D en pantalla
float	**transform_points(float **points, int size, float *view_matrix,
		float *projection_matrix)
{
	float	**screen_points;
	float	w;

	screen_points = malloc(sizeof(float *) * size);
	float view_point[4];
		// Almacenará el punto transformado por la matriz de vista
	for (int i = 0; i < size; i++)
	{
		screen_points[i] = malloc(sizeof(float) * 4);
			// Proyección 4D (homogénea)
		// Paso 1: Multiplicamos el punto por la matriz de vista
		multiply_matrix_vector(view_matrix, points[i], view_point);
		// Paso 2: Multiplicamos el resultado por la matriz de proyección
		multiply_matrix_vector(projection_matrix, view_point, screen_points[i]);
		// Si la proyección es ortográfica, no es necesario normalizar por w
		// Pero si usas perspectiva, necesitarás hacerlo
		w = screen_points[i][3];
		if (w != 0)
		{
			screen_points[i][0] /= w;
			screen_points[i][1] /= w;
			screen_points[i][2] /= w;
		}
		// Imprimir resultados
		printf("3D: (%3.0f, %3.0f, %3.0f, %3.0f) -> ", points[i][0],
			points[i][1], points[i][2], points[i][3]);
		printf("Proyectado: (%3.0f, %3.0f, %3.0f, %3.0f)\n",
			screen_points[i][0], screen_points[i][1], screen_points[i][2],
			screen_points[i][3]);
	}
	return (screen_points);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		size;

	float **points, **screen_points;
	float *view_matrix, *projection_matrix;
	points = read_arguments(argc, argv, &size);
	if (!points)
		return (1);
	view_matrix = set_view_matrix();
	projection_matrix = set_projection_matrix();
	screen_points = transform_points(points, size, view_matrix,
			projection_matrix);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF - MiniLibX");
	if (!data.win)
		return (1);
	for (int i = 0; i < size; i++)
	{
		if (screen_points[i][0] >= 0 && screen_points[i][0] < WIDTH
			&& screen_points[i][1] >= 0 && screen_points[i][1] < HEIGHT)
		{
			mlx_pixel_put(data.mlx, data.win, (int)screen_points[i][0],
				(int)screen_points[i][1], 0xFFFFFF);
		}
	}
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	free(view_matrix);
	free(projection_matrix);
	free_points(points, size);
	free(screen_points);
	return (0);
}
