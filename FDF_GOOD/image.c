/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:10:00 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/02 14:08:14 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void img_put_pixel(t_img *img, int x, int y, int color)
{
	char *dst;


	dst = img->address + (y * img->line_size + x * (img->pixel_size / 8));
	*(unsigned int *)dst = color;
}

void create_image(void *mlx, t_img *img, int width, int height)
{
	img->img = mlx_new_image(mlx, width, height);
	img->address = mlx_get_data_addr(img->img,
	&img->pixel_size,
	&img->line_size,
	&img->endian);
}
