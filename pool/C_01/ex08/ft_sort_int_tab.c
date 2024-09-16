/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:47:42 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/06 13:49:02 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size)
	{
		j = i;
		min = j;
		while (j < size)
		{
			if (tab[j] < tab[min])
			{
				min = j;
			}
			j++;
		}
		if (min != i)
		{
			swap(&tab[i], &tab[min]);
		}
		i++;
	}
}
