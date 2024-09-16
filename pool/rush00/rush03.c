/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:55:04 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/07 19:06:51 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	rush(int col, int row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row && row > 0 && col > 0)
	{
		j = 0;
		while (j < col)
		{
			if ((i == 0 && j == 0) || (i == row - 1 && j == 0))
				ft_putchar('A');
			else if ((i == 0 && j == col - 1) || (i == row - 1 && j == col - 1))
				ft_putchar('C');
			else if ((i == 0) || (j == 0) || (i == row - 1) || (j == col - 1))
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
