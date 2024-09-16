/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:48:27 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/06 11:54:40 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_digits(int n)
{
	int	digits;

	digits = 0;
	while (n > 1)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

void	ft_putnbr(int nb)
{
	char	digit;
	int		n;
	int		digits;
	int		i;

	digits = count_digits(nb);
	i = digits;
	while (i >= 0)
	{
		digit = '0' + nb % 10;
		write(1, &digit, 1);
		i--;
		nb = nb / 10;
	}
}
