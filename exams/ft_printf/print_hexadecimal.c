/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:58:10 by jbutragu          #+#    #+#             */
/*   Updated: 2025/02/04 08:59:45 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf.h"

static char	*hexadec_upper(void)
{
	char	*digits;
	int		i;

	i = 0;
	digits = malloc(sizeof(char) * (16 + 1));
	digits[16] = 0;
	while (i < 10)
	{
		digits[i] = '0' + i;
		i++;
	}
	while (i < 16)
	{
		digits[i] = 'A' + i - 10;
		i++;
	}
	return (digits);
}

static char	*hexadec_lower(void)
{
	char	*digits;
	int		i;

	i = 0;
	digits = malloc(sizeof(char) * (16 + 1));
	digits[16] = 0;
	while (i < 10)
	{
		digits[i] = '0' + i;
		i++;
	}
	while (i < 16)
	{
		digits[i] = 'a' + i - 10;
		i++;
	}
	return (digits);
}

int	put_num_to_hex_with_return(unsigned long long n, int upper)
{
	char	solution[100];
	char	*digits;
	int		len;
	int		i;

	if (upper)
		digits = hexadec_upper();
	else
		digits = hexadec_lower();
	solution[100 - 1] = 0;
	len = 0;
	i = 0;
	while (n != 0)
	{
		len++;
		solution[100 - 1 - len] = digits[n % 16];
		n = n / 16;
	}
	while (solution[100 - 1 - len + i])
	{
		write(1, &solution[100 - 1 - len + i], 1);
		i++;
	}
	return (free(digits), len);
}

int	put_pointer_with_return(unsigned long long n)
{
	if (n != 0)
	{
		write(1, "0x", 2);
		return (put_num_to_hex_with_return(n, 0) + 2);
	}
	else
		return (write(1, "(nil)", 5));
}
