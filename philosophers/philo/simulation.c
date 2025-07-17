/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:32:38 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/12 13:35:40 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philos_health(t_sim *simul, int *eats_rem)
{
	int	i;

	i = 0;
	*eats_rem = 0;
	while (i < simul->num_philos)
	{
		if (check_dead(&simul->philos[i]))
		{
			simul->sim_should_end = 1;
			pthread_mutex_unlock(&simul->check_mutex);
			return (0);
		}
		if (simul->philos[i].num_eats < simul->target_eats)
			++(*eats_rem);
		++i;
	}
	return (1);
}

void	initialice_simulation(t_sim *simul)
{
	int	i;

	simul->philos = malloc(sizeof(t_philo) * simul->num_philos);
	simul->forks = malloc(sizeof(pthread_mutex_t) * simul->num_philos);
	pthread_mutex_init(&simul->write_mutex, 0);
	pthread_mutex_init(&simul->check_mutex, 0);
	i = 0;
	while (i < simul->num_philos)
		pthread_mutex_init(&simul->forks[i++], 0);
	i = 0;
	simul->sim_start = time_in_ms();
	simul->sim_should_end = 0;
	while (i < simul->num_philos)
	{
		simul->philos[i].idx = i;
		simul->philos[i].s = simul;
		simul->philos[i].dead = 0;
		simul->philos[i].lfork = &simul->forks[i];
		simul->philos[i].rfork = &simul->forks[(i + 1) % simul->num_philos];
		simul->philos[i].last_eat = simul->sim_start;
		simul->philos[i].num_eats = 0;
		pthread_create(&simul->philos[i].thread, 0,
			philo_func, &simul->philos[i]);
		++i;
	}
}

void	loop_simulation(t_sim *simul)
{
	int	eats_rem;

	while (1)
	{
		pthread_mutex_lock(&simul->check_mutex);
		if (!check_philos_health(simul, &eats_rem))
			return ;
		pthread_mutex_unlock(&simul->check_mutex);
		pthread_mutex_lock(&simul->check_mutex);
		if (reach_target_eats(eats_rem, simul))
		{
			pthread_mutex_unlock(&simul->check_mutex);
			return ;
		}
		pthread_mutex_unlock(&simul->check_mutex);
		usleep(simul->time_to_death * 1000 / 2 + 1000);
	}
}
