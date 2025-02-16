#ifndef FDF_H

#define FDF_H

#include "minilibx-linux/mlx.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define ESC_KEY 65307 // Código de tecla ESC en X11

typedef struct s_data
{
    void    *mlx;
    void    *win;
}   t_data;

int close_window(t_data *data);
int key_press(int keycode, t_data *data);


#endif