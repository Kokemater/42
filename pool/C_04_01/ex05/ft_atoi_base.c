/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:50:55 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/18 16:16:34 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	val_2dec(char letter, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == letter)
			return (i);
		i++;
	}
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\n' || base[i] == '\f' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v' || base[i] == ' ')
			return (-1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (-1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (-1);
	return (0);
}

int	is_in_the_base(char letter, char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == letter)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	sign;
	int	i;
	int	nbase;

	i = 0;
	num = 0;
	sign = 1;
	if (check_base(base) == -1)
		return (0);
	nbase = ft_strlen(base);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] != '\0') && is_in_the_base(str[i], base))
		num = num * nbase + val_2dec(str[i++], base);
	if (sign == -1)
		num = num * -1;
	return (num);
}
/*
#include <stdio.h>
int main()
{
char str[] = "-+++--021A+3-24 11s1";
char base[] = "0123456789ABCDEF";
printf("%d \n", ft_atoi_base(str,base));
}*/
