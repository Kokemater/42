/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:57:59 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/17 15:59:50 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int	n;
	char	 *dest;

	n = ft_strlen(src);
	dest = malloc(sizeof(char) * n + 1);
	ft_strcpy(dest, src);    
	return (dest);
}
/*
#include <stdio.h>
int main()
{
	char t[] = "hola";
	printf("%s", ft_strdup(t));
}*/
