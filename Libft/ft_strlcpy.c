/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:35:36 by jbutragu          #+#    #+#             */
/*   Updated: 2024/10/07 17:33:02 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	n = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (n);
	while (i < size - 1)
	{
		if (src[i] == '\0')
			break ;
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (n);
}
