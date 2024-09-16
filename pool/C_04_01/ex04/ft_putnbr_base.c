/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:01:09 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/16 15:16:11 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\n' || base[i] == '\f' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v' || base[i] == ' ')
			return (-1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (-1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (-1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	calculate_and_print(int nbr, int *digit, char *base, int nbase)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		if (nbr > 0)
			digit[i] = base[nbr % nbase];
		else
			digit[i] = base[(nbr % nbase) * -1];
		nbr = nbr / nbase;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &digit[i], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	nbase;
	int	i;
	int	digit[100];

	i = 0;
	while (i < 100)
		digit[i++] = 0;
	if (check_base(base) == -1 || nbr == 0)
	{
		if (nbr == 0)
			write(1, "0", 1);
		return ;
	}
	nbase = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
	}
	calculate_and_print(nbr, digit, base, nbase);
}

/*
#include <stdio.h>
int main()
{
	ft_putnbr_base(0,"01");
	printf("\n");
	ft_putnbr_base(-123, "0123456789ABCDEF");
}
*/
