/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:17:03 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/04 10:26:23 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_abs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_min3(float a, float b, float c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}
