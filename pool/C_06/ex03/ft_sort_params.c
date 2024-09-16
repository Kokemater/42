/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:25:09 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/17 15:25:17 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char) s1[i] - (unsigned char) s2[i] != 0)
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	ft_sort_int_tab(char **tab, int size)
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
			if (ft_strcmp(tab[j], tab[min]) < 0)
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

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	ft_sort_int_tab(argv, argc);
	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			write(1, &(argv[j][i]), 1);
			i++;
		}
		j++;
		write(1, "\n", 1);
	}
}
