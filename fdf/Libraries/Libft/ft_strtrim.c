/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:17:56 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/26 10:29:59 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*end;
	const char	*start;
	char		*result;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (ft_strchr(set, *start) || (ft_strchr(set, *end) && end > s1))
	{
		if (ft_strchr(set, *start))
			start++;
		if (ft_strchr(set, *end))
			end--;
	}
	len = end - start + 1;
	if (end < start)
		len = 0;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	ft_memcpy(result, start, len);
	result[len] = 0;
	return (result);
}
