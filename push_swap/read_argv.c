/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:33:29 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 12:52:27 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(const char *s, char c)
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

char	**ft_split_spaces(const char *s)
{
	char	**ret;
	int		wd_it;
	int		word_len;

	if (!s)
		return (0);
	wd_it = 0;
	ret = (char **)malloc(sizeof(char *) * (count_words(s, ' ') + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		while (*s == ' ')
			s++;
		word_len = 0;
		while (s[word_len] && s[word_len] != ' ')
			word_len++;
		if (*s && !add_word(ret, wd_it++, s, word_len))
			return (0);
		s += word_len;
	}
	ret[wd_it++] = 0;
	return (ret);
}

static char	**join(char **result, char **arr1, char **arr2)
{
	int	i;
	int	len1;

	i = 0;
	while (arr1[i])
	{
		result[i] = arr1[i];
		i++;
	}
	len1 = i;
	i = 0;
	while (arr2[i])
	{
		result[len1 + i] = arr2[i];
		i++;
	}
	result[len1 + i] = NULL;
	return (result);
}

char	**join_arrays(char **arr1, char **arr2)
{
	int		len1;
	int		len2;
	char	**result;

	len1 = 0;
	len2 = 0;
	while (arr1[len1])
		len1++;
	while (arr2[len2])
		len2++;
	result = (char **)malloc((len1 + len2 + 1) * sizeof(char *));
	if (!result)
	{
		free_arr(arr1);
		free_arr(arr2);
		return (NULL);
	}
	result = join(result, arr1, arr2);
	free(arr1);
	free(arr2);
	return (result);
}
