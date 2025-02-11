/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:29:44 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 12:24:25 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_arr(char **inputs)
{
	int	i;

	i = 0;
	if (!inputs)
		return ;
	while (inputs[i])
	{
		free(inputs[i]);
		i++;
	}
	free(inputs);
}

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

char	**join(char **result, char **arr1, char **arr2)
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

char	**join_args(int argc, char **argv, int *total_len)
{
	int		i;
	char	**result;
	char	**new;

	result = malloc(sizeof(char *) * 1);
	result[0] = 0;
	*total_len = 0;
	i = 1;
	while (i < argc)
	{
		*total_len += count_words(argv[i], ' ');
		new = ft_split_spaces(argv[i]);
		result = join_arrays(result, new);
		i++;
	}
	i = 0;
	while (result[i])
	{
		// printf("-> %s \n", result[i]);
		i++;
	}
	return (result);
}


int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		errors;
	char	**inputs;
	int		input_len;

	if (argc == 1)
		return (0);
	inputs = join_args(argc, argv, &input_len);
	errors = inspect_errors(input_len, inputs);
	if (errors)
	{
		free_arr(inputs);
		ft_lstclear(&a);

		return (1);
	}
	a = create_list(input_len, inputs);
	if (!a)
	{
		free_arr(inputs);
		ft_lstclear(&a);
		return (1);
	}
	b = NULL;
	order_list(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	free_arr(inputs);
}
