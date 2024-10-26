/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:17:24 by jbutragu          #+#    #+#             */
/*   Updated: 2024/10/07 19:26:36 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	s += start;
	str_len = ft_strlen(s);
	if (str_len < len)
		len = str_len;
	result = malloc(len +1);
	if (!result)
		return (0);
	ft_strlcpy(result, s, len +1);
	return (result);
}
