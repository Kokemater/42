/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:30:09 by jbutragu          #+#    #+#             */
/*   Updated: 2024/09/19 22:47:58 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t num)
{
	size_t			i;

	i = 0;
	while (i < num)
	{
		((unsigned char *) ptr)[i] = val;
		i++;
	}
	return (ptr);
}
