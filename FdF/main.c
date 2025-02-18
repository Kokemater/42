#include "fdf.h"

void print_matrix(float *matrix)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f ", matrix[i * 4 + j]);
        }
        printf("\n");
    }
}

void print_vector(float *vector)
{
    printf("[%.3f, %.3f, %.3f, %.3f]\n", vector[0], vector[1], vector[2], vector[3]);
}

float **read_arguments(int argc, char **argv, int *size)
{
    if (argc != 2)
        return NULL;
    
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return NULL;
    }
    
    return create_points(fd, size);
}

float *set_view_matrix(void)
{
    float Camera[] = {1.0, 1.0, 5.0};
    float Target[] = {0.0f, 0.0f, 0.0f};
    float Up[] = {0.0f, 1.0f, 0.0f};

    return create_view_matrix(Camera, Target, Up);
}

float *ortho_projection_matrix() 
{
    // Definir la matriz de proyección ortográfica en forma unidimensional (1D)
	float *matrix = malloc(sizeof(float) * 16);

    matrix[0] = 1.0f;
    matrix[1] = 0.0f;
    matrix[2] = 0.0f;
    matrix[3] = 0.0f;

    matrix[4] = 0.0f;
    matrix[5] = 1.0f;
    matrix[6] = 0.0f;
    matrix[7] = 0.0f;

    matrix[8] = 0.0f;
    matrix[9] = 0.0f;
    matrix[10] = 0.0f;
    matrix[11] = 0.0f;

    matrix[12] = 0.0f;
    matrix[13] = 0.0f;
    matrix[14] = 0.0f;
    matrix[15] = 1.0f;
	return (matrix);
}
float *set_projection_matrix(void)
{
    float left_right[2] = {-1.0, 1.0};
    float bottom_top[2] = {-1.0, 1.0};
    float near_far[2] = {-1.0, 1.0};
    return create_ortho_projection_matrix(left_right, bottom_top, near_far);
}

void screen_coordinates(float *vector, int width, int height) 
{
	vector[0] = vector[0] / vector[3];
	vector[1] = vector[1] / vector[3];
    // Mapear las coordenadas a las dimensiones de la pantalla
    vector[0] = ((vector[0] + 1.0f) / 2.0f) * width;
    vector[1] = ((vector[1] + 1.0f) / 2.0f) * width;
    
    // Ajustar el sistema de coordenadas para que el eje y crezca hacia abajo
    vector[1] = height -  vector[1];
}

float **transform_points(float **points, int size, float *view_matrix, float *projection_matrix)
{
    float **screen_points = malloc(sizeof(float*) * size);
    float view_point[4];
    
    for (int i = 0; i < size; i++)
    {
        screen_points[i] = malloc(sizeof(float) * 4);
        multiply_matrix_vector(view_matrix, points[i], view_point);
        multiply_matrix_vector(projection_matrix, view_point, screen_points[i]);
		print_vector(screen_points[i]);

        screen_coordinates(screen_points[i], WIDTH, HEIGHT);
		printf("Screen : ");
		print_vector(screen_points[i]);

    }
    return screen_points;
}

int main(int argc, char **argv)
{
    t_data data;
    float **points, **screen_points;
    int size;
    float *view_matrix, *projection_matrix;

    points = read_arguments(argc, argv, &size);
    if (!points)
        return 1;
    
    view_matrix = set_view_matrix();
    projection_matrix = set_projection_matrix();
    screen_points = transform_points(points, size, view_matrix, projection_matrix);
    
    data.mlx = mlx_init();
    if (!data.mlx)
        return 1;
    
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF - MiniLibX");
    if (!data.win)
        return 1;
    
    for (int i = 0; i < size; i++)
        mlx_pixel_put(data.mlx, data.win, (int)screen_points[i][0], (int)screen_points[i][1], 0xFFFFFF);
    
    mlx_key_hook(data.win, key_press, &data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    mlx_loop(data.mlx);
    
    free(view_matrix);
    free(projection_matrix);
    free_points(points, size);
    free(screen_points);
    return 0;
}
