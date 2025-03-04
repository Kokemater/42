/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:36:48 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/26 10:36:49 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	return (0);
}
