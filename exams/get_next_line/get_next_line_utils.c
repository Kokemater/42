/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:23:09 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/30 11:22:10 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_space;
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_space = ft_strlen(s1) + ft_strlen(s2);
	result = (char *) malloc(sizeof(char) * (total_space + 1));
	result[total_space] = 0;
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] && i < total_space)
		result[i++] = s2[j++];
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != 0)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if ((char) c == s[i])
		return ((char *)(s + i));
	return (0);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *) malloc(nmemb * size);
	if (!new)
		return (0);
	while (i < size)
		new[i++] = 0;
	return (new);
}
char	*ft_strndup(const char *src, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *) malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	dest[n] = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
