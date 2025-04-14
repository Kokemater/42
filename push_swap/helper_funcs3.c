/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:31:19 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 12:51:39 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strdup(const char *src)
{
	int		n;
	char	*dest;

	n = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * n + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, n + 1);
	return (dest);
}

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
	result = malloc(len + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s, len + 1);
	return (result);
}
