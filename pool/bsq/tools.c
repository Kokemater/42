/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:45:17 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/24 11:11:23 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	find_min(int *arr, int size)
{
	int	i;
	int	min;

	min = -1;
	i = 0;
	while (i < size)
	{
		if (arr[i] > 0)
		{
			min = i;
			break ;
		}
		i++;
	}
	if (min == -1)
		return (0);
	while (i < size)
	{
		if (arr[i] < arr[min] && arr[i] > 0)
			min = i;
		i++;
	}
	return (arr[min]);
}

int	skip_the_first_line(char *text)
{
	int	i;

	i = 0;
	while (text[i] != '\n')
		i++;
	i++;
	return (i);
}

void	put_answer(char **arr, int *ans, char data)
{
	int	i;
	int	j;
	int	size;

	size = ans[0];
	i = ans[1];
	j = ans[2];
	while (i < size + ans[1])
	{
		j = ans[2];
		while (j < size + ans[2])
		{
			arr[i][j] = data;
			j++;
		}
		i++;
	}
}

void	print_array(char **arr, int *dim)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < dim[0])
	{
		j = 0;
		while (j < dim[1])
		{
			write(1, &arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
