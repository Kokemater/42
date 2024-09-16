/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:15:10 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/06 09:09:51 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	number_to_string(int n, char *number)
{
	number[1] = n % 10 + '0';
	n = n / 10;
	number[0] = n % 10 + '0';
	number[2] = '\0';
}

void	ft_print_comb2(void)
{
	int		n1;
	int		n2;
	char	number_1[3];
	char	number_2[3];

	n1 = 0;
	while (n1 <= 99)
	{
		n2 = n1 +1;
		while (n2 <= 99 && n2 > n1)
		{
			number_to_string(n1, number_1);
			number_to_string(n2, number_2);
			write(1, number_1, 2);
			write(1, " ", 1);
			write(1, number_2, 2);
			if (!(n1 == 98 && n2 == 99))
			{
				write(1, ", ", 2);
			}
			n2++;
		}
		n1++;
	}
}
