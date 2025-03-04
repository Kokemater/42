/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:53:54 by jbutragu          #+#    #+#             */
/*   Updated: 2024/10/03 19:53:26 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		n;
	char	*dest;

	n = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * n + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, n +1);
	return (dest);
}
