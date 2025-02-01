#include "push_swap.h"

int	ft_atoi_binary(char *binary_number)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (binary_number[i])
	{
		total*=2;
		total += (binary_number[i]- '0');
		i++;
	}
	return (total);
}

float	ft_abs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}