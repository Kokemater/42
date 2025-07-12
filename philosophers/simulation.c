/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:32:38 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/12 13:35:40 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sim_init(t_sim *sim)
{
	int	i;

	sim->philos = malloc(sizeof(t_philo) * sim->num_philos);
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->num_philos);
	pthread_mutex_init(&sim->write_mut, 0);
	pthread_mutex_init(&sim->check_mut, 0);
	i = 0;
	while (i < sim->num_philos)
		pthread_mutex_init(&sim->forks[i++], 0);
	i = 0;
	sim->sim_start = timestamp_ms();
	sim->should_end = 0;
	while (i < sim->num_philos)
	{
		sim->philos[i].idx = i;
		sim->philos[i].s = sim;
		sim->philos[i].dead = 0;
		sim->philos[i].lfork = &sim->forks[i];
		sim->philos[i].rfork = &sim->forks[(i + 1) % sim->num_philos];
		sim->philos[i].last_eat = sim->sim_start;
		sim->philos[i].num_eats = 0;
		pthread_create(&sim->philos[i].thread, 0, philo_func, &sim->philos[i]);
		++i;
	}
}

void	sim_loop(t_sim *sim)
{
	int	eats_rem;
	int	i;

	while (1)
	{
		i = 0;
		eats_rem = 0;
		pthread_mutex_lock(&sim->check_mut);
		while (i < sim->num_philos)
		{
			if (check_dead(&sim->philos[i]))
			{
				pthread_mutex_unlock(&sim->check_mut);
				sim->should_end = 1;
				return ;
			}
			if (sim->philos[i].num_eats < sim->target_eats)
				++eats_rem;
			++i;
		}
		pthread_mutex_unlock(&sim->check_mut);
		if (target_eats_reached(eats_rem, sim))
			return ;
		usleep(100);
	}
}
