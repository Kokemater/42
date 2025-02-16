#include "fdf.h"


int main(void)
{
    t_data  data;

    // Inicializar MiniLibX
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);

    // Crear ventana
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FDF - MiniLibX");
    if (!data.win)
        return (1);

    // Dibujar un píxel rojo en el centro
    mlx_pixel_put(data.mlx, data.win, WIDTH / 2, HEIGHT / 2, 0xFF0000);

    // Configurar hooks
    mlx_key_hook(data.win, key_press, &data);
    mlx_hook(data.win, 17, 0, close_window, &data); // Cierra al hacer clic en la 'X'

    // Bucle de eventos
    mlx_loop(data.mlx);

    return (0);
}
