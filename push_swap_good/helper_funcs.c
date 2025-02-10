/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:17:00 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/10 17:20:04 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(const char letter)
{
	if ((letter == '\n' || letter == '\f' || letter == '\r' || letter == '\t'
			|| letter == '\v' || letter == ' '))
		return (1);
	else
		return (0);
}

int	is_a_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	skip_spaces(int *i, int *sign, const char *str)
{
	while (str[*i] == ' ' || is_space(str[*i]))
		i++;
	if (str[*i] == '-')
	{
		*sign *= -1;
		i++;
	}
	if (str[*i] == '+' && (*i == 0 || str[*i - 1] != '-'))
		i++;
}

int	ft_atoi_checker(const char *str, int *error)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	skip_spaces(&i, &sign, str);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			*error = 1;
			return (0);
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		num = num * -1;
	*error = 0;
	return (num);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+' && (i == 0 || str[i - 1] != '-'))
		i++;
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		num = num * -1;
	return (num);
}
