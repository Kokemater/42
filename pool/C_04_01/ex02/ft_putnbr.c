/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:48:27 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/16 14:18:18 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	calculate_and_print(int nb, char *digit)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		if (nb > 0)
			digit[i++] = nb % 10 + '0';
		else
			digit[i++] = (nb % 10) * -1 + '0';
		nb = nb / 10;
	}
	i--;
	while (i >= 0)
	{
		write(1, &digit[i], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	char	digit[15];
	int		i;

	i = 0;
	while (i < 15)
		digit[i++] = 0;
	i = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	calculate_and_print(nb, digit);
}
/*
#include <stdio.h>
int main(void)
{
	//printf("%d ", -15 % 10);
	ft_putnbr(-2147483648);
} 
*/
