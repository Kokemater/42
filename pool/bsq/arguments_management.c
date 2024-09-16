/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:17:27 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/24 11:17:29 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*stdin_to_string(void)
{
	int		len;
	char	temp[1000024];
	char	*buf;

	len = read(0, temp, 1024);
	if (len == 0)
		exit(1);
	temp[len] = '\0';
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		print_error();
	ft_strncpy(buf, temp, len);
	return (buf);
}
