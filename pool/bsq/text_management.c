/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:47:46 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/24 12:38:49 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*data_of_the_arr(char *text)
{
	char	*data;
	int		i;

	i = 0;
	data = malloc(sizeof(char) * 3);
	if (!data)
		print_error();
	while (text[i] >= '0' && text[i] <= '9')
		i++;
	data[0] = text[i];
	data[1] = text[i + 1];
	data[2] = text[i + 2];
	return (data);
}

char	*txt_to_string(char *filename)
{
	int		len;
	char	temp[MAX_IN_TIME];
	char	*buf;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error();
	len = read(fd, temp, MAX_IN_TIME - 1);
	if (len == 0)
		print_error();
	temp[len] = '\0';
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		print_error();
	ft_strncpy(buf, temp, len);
	return (buf);
}

int	*dimensions(char *text)
{
	int	index;
	int	initial_index;
	int	*dim;

	index = 0;
	dim = malloc(sizeof(int) * 2);
	if (!dim)
		print_error();
	dim[0] = 0;
	while ((text[index] != '\0') && (text[index] >= '0' && text[index] <= '9'))
	{
		dim[0] = dim[0] * 10 + (text[index] - '0');
		index++;
	}
	initial_index = skip_the_first_line(text);
	if (dim[0] == 0)
		print_error();
	index = initial_index;
	while (text[index] != '\n')
		index++;
	dim[1] = index - initial_index;
	return (dim);
}

char	**initialize_arr(char *text)
{
	int		index;
	char	**new;
	int		*dim;

	dim = dimensions(text);
	index = 0;
	new = malloc(sizeof(char *) * (dim[0]));
	if (!new)
		print_error();
	while (index < dim[0])
	{
		new[index] = malloc(sizeof(char) * dim[1]);
		if (!new[index])
			print_error();
		index++;
	}
	free(dim);
	return (new);
}

char	**create_arr(char *text)
{
	int		i;
	int		j;
	int		index;
	int		*dim;
	char	**new;

	new = initialize_arr(text);
	dim = dimensions(text);
	index = skip_the_first_line(text);
	i = 0;
	while (i < dim[0])
	{
		j = 0;
		while (j < dim[1])
		{
			if (text[index] != '\n')
				new[i][j] = text[index];
			index++;
			j++;
		}
		index++;
		i++;
	}
	free(dim);
	return (new);
}
