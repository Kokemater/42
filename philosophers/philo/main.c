/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:32:08 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/12 13:45:49 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_simulation(t_sim *simul)
{
	int	i;

	i = 0;
	while (i < simul->num_philos)
	{
		pthread_join(simul->philos[i].thread, 0);
		i++;
	}
	i = 0;
	while (i < simul->num_philos)
	{
		pthread_mutex_destroy(&simul->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&simul->write_mutex);
	pthread_mutex_destroy(&simul->check_mutex);
	free(simul->philos);
	free(simul->forks);
}

static int	set_simulation_parameters(t_sim *simul, int argc, char **argv)
{
	simul->num_philos = ft_atoi(argv[1]);
	simul->time_to_death = ft_atoi(argv[2]);
	simul->time_to_eat = ft_atoi(argv[3]);
	simul->time_to_sleep = ft_atoi(argv[4]);
	simul->target_eats = 0;
	if (argc == 6)
		simul->target_eats = ft_atoi(argv[5]);
	if (argc == 6 && simul->target_eats == 0)
		return (0);
	return (1);
}

static int	errors_in_parameters(t_sim simul)
{
	if (simul.time_to_sleep < 0 || simul.target_eats < 0
		|| simul.time_to_death < 0 || simul.time_to_eat < 0
		|| simul.num_philos < 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sim	simul;

	if (argc < 5 || argc > 6)
		return (1);
	if (!set_simulation_parameters(&simul, argc, argv))
		return (0);
	if (errors_in_parameters(simul))
		return (1);
	initialice_simulation(&simul);
	loop_simulation(&simul);
	free_simulation(&simul);
	return (0);
}
