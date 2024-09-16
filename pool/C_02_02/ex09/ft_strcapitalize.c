/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:41:08 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/18 09:32:43 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char letter)
{
	int	is_alphan;

	if ((letter >= 'a' && letter <= 'z')
		|| (letter >= 'A' && letter <= 'Z')
		|| (letter >= '0' && letter <= '9'))
	{
		is_alphan = 1;
	}
	else
	{
		is_alphan = 0;
	}
	return (is_alphan);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	dist;

	dist = 97 - 65;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + dist;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& (i == 0
				|| ((i > 0) && !is_alphanumeric(str[i - 1]))))
			str[i] = str[i] - dist;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	char t[] = "s ASDFSF as 34-234a+a`a+`a+`z++89j j J 9k98-x+p";
	printf("%s",ft_strcapitalize(t));
}*/
