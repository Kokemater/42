/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:00:07 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/18 16:17:22 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char letter)
{
	if ((letter == '\n' || letter == '\f' || letter == '\r'
			|| letter == '\t' || letter == '\v' || letter == ' '))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		num = num * -1;
	return (num);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
printf("%d", ft_atoi("         --02147483647"));
}
*/
