/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:09:34 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/04 12:09:59 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sep(const char *s1, const char *s2, const char sep)
{
	char	*dest;
	size_t	size;
	size_t	s1_s;

	if (!s1 && !s2)
		return (0);
	s1_s = ft_strlen(s1);
	size = s1_s + ft_strlen(s2) + 2;
	dest = malloc(size * sizeof(char));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, size);
	dest[s1_s] = sep;
	dest[s1_s + 1] = 0;
	ft_strlcat(dest, s2, size);
	return (dest);
}
