/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:00:20 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/17 11:18:16 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_left_then_right(t_philo *phil)
{
	if (sim_should_end(phil, FALSE, FALSE))
		return (0);
	pthread_mutex_lock(phil->lfork);
	if (sim_should_end(phil, TRUE, FALSE))
		return (0);
	print_status(phil, "has taken a fork");
	if (phil->s->num_philos == 1)
	{
		pthread_mutex_unlock(phil->lfork);
		return (0);
	}
	pthread_mutex_lock(phil->rfork);
	if (sim_should_end(phil, TRUE, TRUE))
		return (0);
	print_status(phil, "has taken a fork");
	return (1);
}

int	take_right_then_left(t_philo *phil)
{
	if (sim_should_end(phil, FALSE, FALSE))
		return (0);
	pthread_mutex_lock(phil->rfork);
	if (sim_should_end(phil, FALSE, TRUE))
		return (0);
	print_status(phil, "has taken a fork");
	if (phil->s->num_philos == 1)
	{
		pthread_mutex_unlock(phil->rfork);
		return (0);
	}
	pthread_mutex_lock(phil->lfork);
	if (sim_should_end(phil, TRUE, TRUE))
		return (0);
	print_status(phil, "has taken a fork");
	return (1);
}

int	take_forks(t_philo *phil)
{
	int	ret;

	if (phil->idx % 2 == 0)
		ret = take_left_then_right(phil);
	else
		ret = take_right_then_left(phil);
	return (ret);
}
