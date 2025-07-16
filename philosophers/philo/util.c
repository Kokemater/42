/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:31:57 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/12 13:31:58 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		result = (result * 10) + (*str - '0');
		++str;
	}
	return (result * sign);
}

long	time_in_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, 0);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	print_status(t_philo *phil, const char *status)
{
	pthread_mutex_lock(&phil->s->write_mutex);
	printf("%li %i %s\n",
		time_in_ms() - phil->s->sim_start, phil->idx + 1, status);
	pthread_mutex_unlock(&phil->s->write_mutex);
}

int	reach_target_eats(int rem, t_sim *s)
{
	if (rem == 0 && s->target_eats != 0)
	{
		s->sim_should_end = 1;
		return (1);
	}
	return (0);
}
