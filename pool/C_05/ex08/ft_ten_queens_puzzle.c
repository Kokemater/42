/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:58:25 by jbutragu          #+#    #+#             */
/*   Updated: 2024/07/17 11:08:45 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_safe(int board[10], int row, int col)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (i != col && board[i] != -1
			&& ((board[i] - i == row - col)
				|| (board[i] + i == row + col)
				|| (board[i] == row)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	free_squares(int board[10], int *col)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (board[i] == -1)
		{
			*col = i;
			return (1);
		}
		i++;
	}
	return (0);
}

void	print_board(int board[10])
{
	int		i;
	char	letter;

	i = 0;
	while (i < 10)
	{
		letter = board[i] + '0';
		write(1, &letter, 1);
		i++;
	}
	write(1, "\n", 1);
}

//  backtracking
int	queens_backtracking(int board[10], int *total)
{
	int	col;
	int	row;

	if (!free_squares(board, &col))
	{
		(*total)++;
		print_board(board);
		return (0);
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(board, row, col))
		{
			board[col] = row;
			if (queens_backtracking(board, total))
			{
				return (1);
			}
			board[col] = -1;
		}
		row++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (i < 10)
		board[i++] = -1;
	queens_backtracking(board, &total);
	return (total);
}
/*
#include <stdio.h>
int main(void)
{
int d= ft_ten_queens_puzzle();
printf("%d", d);
}
*/
