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

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}
float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}
float	ft_min3(float a, float b, float c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;
	return c;
}