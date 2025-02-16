/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:22:09 by jbutragu          #+#    #+#             */
/*   Updated: 2024/10/07 18:28:35 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*little))
		return ((char *)big);
	j = 0;
	while (big[j] && j < len)
	{
		i = 0;
		while (i + j < len && little[i] && little[i] == big[i + j])
			i++;
		if (!little[i])
			return ((char *)(big + j));
		j++;
	}
	return (0);
}
