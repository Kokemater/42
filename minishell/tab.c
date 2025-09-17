/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoraled <dmoraled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:27:07 by dmoraled          #+#    #+#             */
/*   Updated: 2025/06/19 12:27:08 by dmoraled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tab_length(char **tab)
{
	int	n;

	n = 0;
	while (*tab)
	{
		++n;
		++tab;
	}
	return (n);
}

void	tab_free(char **tab)
{
	char	**p;

	if (!tab)
		return ;
	p = tab;
	while (*p)
	{
		free(*p);
		p++;
	}
	free(tab);
}

int	tab_strlen(char **tab)
{
	int	l;

	l = 0;
	while (*tab)
	{
		l += ft_strlen(*tab);
		++tab;
	}
	return (l);
}

char	*tab_join(char **tab)
{
	int		len;
	char	**it;
	char	*ret;

	len = 0;
	it = tab;
	while (*it)
	{
		len += ft_strlen(*it);
		++it;
	}
	it = tab;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	*ret = 0;
	while (*it)
	{
		ft_strlcat(ret, *it, len + 1);
		++it;
	}
	return (ret);
}
