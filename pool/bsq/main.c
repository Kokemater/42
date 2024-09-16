/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:46:04 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/24 12:04:00 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

void	free_all(int *ans, int *dim, char *data, char **array)
{
	int	i;

	i = 0;
	while (i < dim[0])
	{
		free(array[i]);
		i++;
	}
	free(array);
	free(ans);
	free(dim);
	free(data);
}

void	draw(char *text)
{
	int		*ans;
	int		*dim;
	char	*data;
	char	**array;


	data = data_of_the_arr(text);
	array = create_arr(text);
	dim = dimensions(text);
	ans = find_biggest_square(array, dim, data);
	put_answer(array, ans, data[2]);
	print_array(array, dim);
	free(text);
	free_all(ans, dim, data, array);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*text;

	if (argc == 1)
	{
		text = stdin_to_string();
		draw(text);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			text = txt_to_string(argv[i]);
			draw(text);
			if (i + 1 != argc)
				write(1, "\n", 1);
			i++;
		}
	}
}
