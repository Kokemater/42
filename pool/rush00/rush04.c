/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:16:01 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/07 18:08:04 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	rush(int col, int row)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row && col > 0 && row > 0)
	{
		j = 0;
		while (j < col)
		{
			if ((i == 0 && j == 0) || (i == row -1 && j == col -1))
				ft_putchar('A');
			else if ((i == 0 && j == col - 1) || (i == row -1 && j == 0))
				ft_putchar('C');
			else if (i == 0 || i == row -1 || j == 0 || j == col -1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
