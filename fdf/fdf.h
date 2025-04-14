#ifndef FDF_H

# define FDF_H

# include "Libraries/Libft/libft.h"
# include "Libraries/get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>

# define WIDTH 2400
# define HEIGHT 1800
# define ESC_KEY 65307 // Código de tecla ESC en X11
# define SCALE 3

typedef struct s_img
{
	void	*img;
	char	*address;
	int		pixel_size;
	int		line_size;
	int		endian;
} t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	float	**w_points;
	float **s_points;
	int	size;
}			t_data;



int			close_window(t_data *data);
int			key_press(int keycode, t_data *data);

void		print_points(float **points, int n_points);
void		free_points(float **points, int size);
float		**create_points(int fd, int *size, int i);

void	draw_line_dda(t_data data, float *p1, float *p2, float *world);
void		connect_points_using_dda(t_data data, float **screen_points,
				float **world_points, int size);
void	put_points(t_data data, float **screen_points, int size, float **world_points);


void img_put_pixel(t_img *img, int x, int y, int color);
void create_image(void *mlx, t_img *img, int width, int height);
#endif