/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:31:51 by jbutragu          #+#    #+#             */
/*   Updated: 2024/10/07 19:09:41 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int	num_len(int n)
{
	int	ans;

	ans = 0;
	if (n < 0)
		++ans;
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++ans;
	}
	return (ans);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ans;
	char	digit;

	len = num_len(n);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (0);
	ans[len--] = 0;
	if (n < 0)
		ans[0] = '-';
	else if (n == 0)
		ans[0] = '0';
	while (n != 0)
	{
		digit = (n % 10);
		n /= 10;
		if (digit < 0)
			digit = -digit;
		ans[len--] = digit + '0';
	}
	return (ans);
}
