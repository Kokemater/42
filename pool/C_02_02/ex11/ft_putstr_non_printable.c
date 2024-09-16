/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:26:51 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/18 11:14:19 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	is_impr;
	int	i;

	is_impr = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (! (str[i] >= 32 && str[i] <= 126))
		{
			is_impr = 0;
		}
		i++;
	}
	return (is_impr);
}

void	num_to_hex(int num)
{
	char	base[16];
	char	letter;
	char	i;
	int		index;

	index = 0;
	i = '0';
	while (index < 10)
	{
		base[index++] = i;
		i++;
	}
	i = 'a';
	while (index < 16)
	{
		base[index++] = i;
		i++;
	}
	if (num / 16 > 0)
	{
		num_to_hex(num / 16);
	}
	letter = base[num % 16];
	write(1, &letter, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (! (str[i] >= 32 && str[i] <= 126))
		{
			write(1, "\\", 1);
			if (str[i] < 16)
				write(1, "0", 1);
			num_to_hex(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
/*
#include <stdio.h>
int main(void)
{
	char texto[7];
	texto[0] = 'a';
	texto[1] = 15;
	texto[2] = 127;
	texto[3] = 10;
	texto[4] = 31;
	texto[5] = 35;
	texto[6] = 0;
	ft_putstr_non_printable(texto);
}
*/
