#include "fdf.h"

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

int key_press(int keycode, t_data *data)
{
    if (keycode == ESC_KEY)
        close_window(data);
    return (0);
}