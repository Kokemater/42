#include "push_swap.h"



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