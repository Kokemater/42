/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:57:44 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/17 16:58:06 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	index;


	range = malloc(sizeof(int) * (max - min) + 1);
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
    if (!range)
        return (0);
	i = min;
	index = 0;
	while (i < max)
	{
		range[index] = i;
		index++;
		i++;
	}
	return (range);
}
/*
#include <stdio.h>
int main(void)
{
int *t = ft_range(0, 99);
for (int i = 0; i < 99; i++)
{
printf("%d ", t[i]);
}
}
*/
