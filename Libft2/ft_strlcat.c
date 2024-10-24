/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:57:20 by jbutragu          #+#    #+#             */
/*   Updated: 2024/10/03 20:59:17 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	last_index;
	size_t	initial_l_src;

	i = 0;
	initial_l_src = ft_strlen(src);
	last_index = ft_strlen(dst);
	if (size <= last_index)
		return (initial_l_src + size);
	while (src[i] != '\0' && last_index + i < size -1)
	{
		dst[last_index + i] = src[i];
		i++;
	}
	dst[i + last_index] = '\0';
	return (initial_l_src + last_index);
}
