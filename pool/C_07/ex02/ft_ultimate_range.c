#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	index;

	i = min;
	index = 0;
	*range = malloc(sizeof(int) * (max - min) + 1);
    if ((*range) == 0)
	{
		return (-1);
	}
	if (min >= max)
	{
		return (0);
	}
	while (i < max)
	{
		(*range)[index] = i;
		index++;
		i++;
	}
	return (max - min);
}
/*
#include <stdio.h>
int main(void)
{
int *range;
int t = ft_ultimate_range(&range, 0, 99);

for (int i = 0; i < 99; i++)
{
printf("%d ", (range)[i]);
}
}
*/
