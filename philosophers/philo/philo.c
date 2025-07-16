/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:32:04 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/12 13:32:05 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *phil)
{
	if (!phil->dead
		&& phil->s->time_to_death < (time_in_ms() - phil->last_eat))
	{
		print_status(phil, "died");
		phil->dead = 1;
		phil->s->sim_should_end = 1;
		return (1);
	}
	return (0);
}

static int	sim_should_end(t_philo *phil, int unlock_left, int unlock_right)
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

static int	take_forks(t_philo *phil)
{
	if (0)
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
	}
	else
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
	}
	return (1);
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
	if (phil->idx% 2 != 0)
		usleep(phil->s->num_philos * 1000);
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
