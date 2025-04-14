/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:37:03 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/11 17:42:19 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**join_args(int argc, char **argv, int *total_len)
{
	int		i;
	char	**result;
	char	**new;

	result = malloc(sizeof(char *) * 1);
	if (!result)
		return (NULL);
	result[0] = 0;
	*total_len = 0;
	i = 1;
	while (i < argc)
	{
		*total_len += count_words(argv[i], ' ');
		new = ft_split_spaces(argv[i]);
		result = join_arrays(result, new);
		i++;
	}
	i = 0;
	return (result);
}
