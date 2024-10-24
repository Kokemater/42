/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:17:56 by jbutragu          #+#    #+#             */
/*   Updated: 2024/10/15 16:35:32 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*end;
	const char	*start;
	char		*result;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (ft_strchr(set, *start) || ft_strchr(set, *end))
	{
		if (ft_strchr(set, *start))
			start++;
		if (ft_strchr(set, *end))
			end--;
	}
	len = end - start + 1;
	if (end < start)
		len = 0;
	result = (char *) malloc(len + 1);
	if (!result)
		return (0);
	ft_memcpy(result, start, len);
	result[len] = 0;
	return (result);
}
/*
int main(void)
{
	char a[] = "ooooooaooooo";
	char b[] = "oe";


	printf("%s \n", ft_strtrim("ooooooaooooo",b));
		printf("%s\n", ft_strtrim(a,b));
			printf("%s\n", ft_strtrim("ooooooaoooooa",b));
				printf("%s\n", ft_strtrim("ooooooaaaooooo",b));
					printf("%s\n", ft_strtrim("ooooooooooooa",b));
					printf("%s\n", ft_strtrim("oe",b));
					printf("%s\n", ft_strtrim("oo",b));
					printf("%s\n", ft_strtrim("ooo",b));
					printf("%s\n", ft_strtrim("ooooooooooo",b));

}*/
