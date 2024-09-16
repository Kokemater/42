/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:31:48 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/06 11:19:35 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_nums(int a, int b, int c)
{
	char	first;
	char	second;
	char	third;

	if (c > b && b > a)
	{
		first = a + '0';
		second = b + '0';
		third = c + '0';
		if (a == 7 && b == 8 && c == 9)
		{
			write(1, &first, 1);
			write(1, &second, 1);
			write(1, &third, 1);
		}
		else
		{
			write(1, &first, 1);
			write(1, &second, 1);
			write(1, &third, 1);
			write(1, ",", 1);
			write(1, " ", 1);
		}
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	c = 0;
	while (a <= 7)
	{
		b = 0;
		while (b <= 8)
		{
			c = 0;
			while (c <= 9)
			{
				write_nums(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
