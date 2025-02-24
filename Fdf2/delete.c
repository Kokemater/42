#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "fdf.h"

#define WIDTH 800
#define HEIGHT 600

// Función para leer los puntos desde un archivo
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
    
    return create_points(fd, size);  // Suponiendo que `create_points` esté implementada
}

// Función para crear la matriz de vista
float *set_view_matrix(void)
{
    float *view_matrix = malloc(sizeof(float) * 16);
    for (int i = 0; i < 16; i++)
    {
        view_matrix[i] = 0;
    }
    view_matrix[0] = 1;
    view_matrix[5] = 1;
    view_matrix[10] = 1;
    view_matrix[14] = -55;
    view_matrix[15] = 1;
    return view_matrix;
}

// Función para crear la matriz de proyección ortográfica
float *ortho_projection_matrix(void)
{
    float *proy_matrix = malloc(sizeof(float) * 16);
    for (int i = 0; i < 16; i++)
    {
        proy_matrix[i] = 0;
    }
    proy_matrix[0] = 1.0f;
    proy_matrix[5] = 1.0f;
    proy_matrix[10] = -0.2f;
    proy_matrix[11] = -1.0f;
    proy_matrix[14] = 1.0f;
    return proy_matrix;
}

// Función para crear la matriz de proyección
float *set_projection_matrix(void)
{
    return ortho_projection_matrix();  // Aquí solo usamos la proyección ortográfica
}

// Función para normalizar un vector
void normalize_vector(float *v) {
    float length = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    for (int i = 0; i < 3; i++) {
        v[i] /= length;
    }
}

// Función para calcular el producto cruzado entre dos vectores
void cross_product(float *a, float *b, float *result) {
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = a[2] * b[0] - a[0] * b[2];
    result[2] = a[0] * b[1] - a[1] * b[0];
}

// Función para calcular el producto punto entre dos vectores
float dot_product(float *a, float *b) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

// Función para construir la matriz de vista (LookAt)
void look_at_matrix(float *camera_pos, float *camera_target, float *camera_up, float *view_matrix)
{
    float forward[3], right[3], up[3];

    // Calcular el vector forward (mirando hacia el target)
    for (int i = 0; i < 3; i++) {
        forward[i] = camera_target[i] - camera_pos[i];
    }
    normalize_vector(forward);

    // Calcular el vector right (cruzado con el up)
    cross_product(camera_up, forward, right);
    normalize_vector(right);

    // Calcular el vector up
    cross_product(forward, right, up);

    // Construir la matriz de vista
    view_matrix[0] = right[0];
    view_matrix[1] = up[0];
    view_matrix[2] = -forward[0];
    view_matrix[3] = 0.0f;

    view_matrix[4] = right[1];
    view_matrix[5] = up[1];
    view_matrix[6] = -forward[1];
    view_matrix[7] = 0.0f;

    view_matrix[8] = right[2];
    view_matrix[9] = up[2];
    view_matrix[10] = -forward[2];
    view_matrix[11] = 0.0f;

    view_matrix[12] = -dot_product(right, camera_pos);
    view_matrix[13] = -dot_product(up, camera_pos);
    view_matrix[14] = dot_product(forward, camera_pos);
    view_matrix[15] = 1.0f;
}

// Función para transformar los puntos 3D a coordenadas 2D en pantalla
void transform_points(float **points, int size, float *view_matrix, float *projection_matrix)
{
    float view_point[4]; // Almacenará el punto transformado por la matriz de vista

    for (int i = 0; i < size; i++) {
        // Paso 1: Multiplicamos el punto por la matriz de vista
        multiply_matrix_vector(view_matrix, points[i], view_point);

        // Paso 2: Multiplicamos el resultado por la matriz de proyección
        multiply_matrix_vector(projection_matrix, view_point, points[i]);

        // Si la proyección es ortográfica, no es necesario normalizar por w
        // Pero si usas perspectiva, necesitarás hacerlo
        float w = points[i][3];
        if (w != 0) {
            points[i][0] /= w;
            points[i][1] /= w;
            points[i][2] /= w;
        }

        // Imprimir resultados
        printf("3D: (%3.0f, %3.0f, %3.0f, %3.0f) -> ",
               points[i][0], points[i][1], points[i][2], points[i][3]);
        printf("Proyectado: (%3.0f, %3.0f, %3.0f, %3.0f)\n",
               points[i][0], points[i][1], points[i][2], points[i][3]);
    }
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
    
    view_matrix = malloc(sizeof(float) * 16);
    projection_matrix = set_projection_matrix();

    // Definir la posición de la cámara, objetivo y "arriba"
    float camera_pos[3] = {10.0f, 10.0f, 10.0f};  // Ejemplo de posición de la cámara
    float camera_target[3] = {0.0f, 0.0f, 0.0f}; // A dónde está mirando
    float camera_up[3] = {0.0f, 1.0f, 0.0f};     // El vector "arriba" de la cámara

    // Construir la matriz de vista
    look_at_matrix(camera_pos, camera_target, camera_up, view_matrix);

    // Transformar los puntos
    transform_points(points, size, view_matrix, projection_matrix);
    
    data.mlx = mlx_init();
    if (!data.mlx)
        return 1;
    
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF - MiniLibX");
    if (!data.win)
        return 1;
    
    for (int i = 0; i < size; i++)
    {
        mlx_pixel_put(data.mlx, data.win, (int)points[i][0], (int)points[i][1], 0xFFFFFF);
    }

    mlx_key_hook(data.win, key_press, &data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    mlx_loop(data.mlx);
    
    free(view_matrix);
    free(projection_matrix);
    free_points(points, size);
    free(screen_points);
    return 0;
}