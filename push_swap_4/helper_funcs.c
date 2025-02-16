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

char	*ft_itoa_binary_len(int n, int len)
{
	char	*binary;
	char	*solution;
	int		number_cpy;

	binary = "01";

	solution = malloc(sizeof(char) * (len + 1));
	if (!solution)
		return (NULL);
	solution[len] = 0;
	while (len > 0)
	{
		len--;
		solution[len] = binary[n%2];
		n /= 2;
	}
	return (solution);
}


int n_binary_digits(int n)
{
	int	len;

	len = 0;
	while(n != 0)
	{
		n /= 2;
		len++;
	}
	return (len);
}

