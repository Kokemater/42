/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:23:34 by dmoraled          #+#    #+#             */
/*   Updated: 2025/06/22 19:49:06 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*next_var_delim(char *str)
{
	if (!str)
		return (0);
	if (*str == '?')
		return (str + 1);
	while (*str && *str != '$' && ft_isalnum(*str))
		++str;
	if (!(*str))
		return (0);
	else
		return (str);
}

static int	count_vars(char *str)
{
	int	c;

	c = 0;
	if (*str != '$')
		++c;
	str = next_var_delim(str);
	while (str && *str)
	{
		++str;
		str = next_var_delim(str);
		++c;
	}
	return (c);
}

char	**var_split(char *str)
{
	int		c;
	int		i;
	char	**ret;

	c = count_vars(str);
	ret = (char **)ft_calloc((c + 1), sizeof(char *));
	if (!ret)
		return (0);
	i = 0;
	while (c > 0 && str && *str)
	{
		ret[i++] = ft_substr(str, 0,
				ft_strlen(str) - ft_strlen(next_var_delim(str + 1)));
		if (!ret[i - 1])
			return (0);
		if (*str)
			str = next_var_delim(str + 1);
		--c;
	}
	return (ret);
}
