/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:57:20 by jbutragu          #+#    #+#             */
/*   Updated: 2024/10/07 19:29:10 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_space;
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_space = ft_strlen(s1) + ft_strlen(s2);
	result = (char *) malloc(sizeof(char) * total_space + 1);
	if (!result)
		return (NULL);
	while (s1[i] != 0)
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = 0;
	return (result);
}
