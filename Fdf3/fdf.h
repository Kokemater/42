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

# define WIDTH 800
# define HEIGHT 600
# define ESC_KEY 65307 // Código de tecla ESC en X11
# define SCALE 5

typedef struct s_data
{
	void	*mlx;
	void	*win;
}			t_data;

typedef struct s_fdflist
{
	float data[4];
	struct s_list_fdf* next;
} t_fdflist;


int			close_window(t_data *data);
int			key_press(int keycode, t_data *data);

void		print_points(float **points, int n_points);
void		free_points(float **points, int size);
t_list *create_points(int fd, int *size, int i);
void	draw_line_dda(t_data data, float *p1, float *p2, float *world);
void		connect_points_using_dda(t_data data, float **screen_points,
				float **world_points, int size);
void	put_points(t_data data, float **screen_points, int size, float **world_points);
#endif