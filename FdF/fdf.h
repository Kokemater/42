#ifndef FDF_H

# define FDF_H

# include "Libraries/Libft/libft.h"
# include "Libraries/get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <math.h>

# define WIDTH 800
# define HEIGHT 600
# define ESC_KEY 65307 // Código de tecla ESC en X11

typedef struct s_data {
    void    *mlx;
    void    *win;
    float   *view_matrix;
} t_data;

int			close_window(t_data *data);
int			key_press(int keycode, t_data *data);

void		print_points(float **points, int n_points);
void		free_points(float **points, int size);
float		**create_points(int fd, int *size);

void subtract_vectors(const float *a, const float *b, float *result);
void normalize(float *v);
void cross_product(const float *a, const float *b, float *result);
float* create_view_matrix(const float *camera, const float *target, const float *up);
void multiply_matrix_vector(const float *matrix, const float *point, float *result);
void apply_isometric_projection(const float *view_matrix, float *point);
void convert_to_screen_coordinates(float *point, int width, int height);
float	*create_ortho_projection_matrix(const float left_right[2],
		const float bottom_top[2], const float near_far[2]);

void	print_points2(int **points, int n_points);
void	free_points2(int **points, int size);
#endif