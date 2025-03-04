/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:24:41 by jbutragu          #+#    #+#             */
/*   Updated: 2025/03/02 12:24:46 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	atoi_hexadecimal(const char *hex)
{
	int	result;

	result = 0;
	hex += 2;
	while (*hex)
	{
		result *= 16;
		if (*hex >= '0' && *hex <= '9')
			result += *hex - '0';
		else if (*hex >= 'A' && *hex <= 'F')
			result += *hex - 'A' + 10;
		else if (*hex >= 'a' && *hex <= 'f')
			result += *hex - 'a' + 10;
		hex++;
	}
	return (result);
}
