/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:13:34 by jbutragu          #+#    #+#             */
/*   Updated: 2024/10/09 20:49:31 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (ret);
		while (*s && *s != c)
			s++;
		ret++;
	}
	return (ret);
}

static int	add_word(char **split, int wd_it, const char *s, int word_len)
{
	int	i;

	split[wd_it] = ft_substr(s, 0, word_len);
	if (split[wd_it])
		return (1);
	i = 0;
	while (i < wd_it)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		wd_it;
	int		word_len;

	if (!s)
		return (0);
	wd_it = 0;
	ret = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		word_len = 0;
		while (s[word_len] && s[word_len] != c)
			word_len++;
		if (*s && !add_word(ret, wd_it++, s, word_len))
			return (0);
		s += word_len;
	}
	ret[wd_it++] = 0;
	return (ret);
}
