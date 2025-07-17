/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:32:04 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/17 11:04:16 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sim_should_end(t_philo *phil, int unlock_left, int unlock_right)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&phil->s->check_mutex);
	if (phil->s->sim_should_end)
	{
		ret = 1;
		if (unlock_left)
			pthread_mutex_unlock(phil->lfork);
		if (unlock_right)
			pthread_mutex_unlock(phil->rfork);
	}
	pthread_mutex_unlock(&phil->s->check_mutex);
	return (ret);
}

static int	eat(t_philo *phil)
{
	print_status(phil, "is eating");
	pthread_mutex_lock(&phil->s->check_mutex);
	phil->last_eat = time_in_ms();
	phil->num_eats++;
	pthread_mutex_unlock(&phil->s->check_mutex);
	usleep(phil->s->time_to_eat * 1000);
	pthread_mutex_unlock(phil->lfork);
	pthread_mutex_unlock(phil->rfork);
	return (!sim_should_end(phil, FALSE, FALSE));
}

void	*philo_func(void *arg)
{
	t_philo	*phil;

	phil = (t_philo *)arg;
	while (1)
	{
		if (!take_forks(phil))
			break ;
		if (!eat(phil))
			break ;
		print_status(phil, "is sleeping");
		usleep(phil->s->time_to_sleep * 1000);
		if (sim_should_end(phil, FALSE, FALSE))
			break ;
		print_status(phil, "is thinking");
	}
	return (0);
}
