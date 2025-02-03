#include "push_swap.h"

static int	is_space(const char letter)
{
		if ((letter == '\n' || letter == '\f' || letter == '\r'
						|| letter == '\t' || letter == '\v' || letter == ' '))
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


int	ft_atoi(const char *str)
{
	long	num;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	num = 0;
	while (is_space(str[i]))
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



