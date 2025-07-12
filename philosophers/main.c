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

static void	sim_free(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_philos)
		pthread_join(sim->philos[i++].thread, 0);
	i = 0;
	while (i < sim->num_philos)
		pthread_mutex_destroy(&sim->forks[i++]);
	pthread_mutex_destroy(&sim->write_mut);
	pthread_mutex_destroy(&sim->check_mut);
	free(sim->philos);
	free(sim->forks);
}


static void set_simulation_parameters(t_sim *sim, int argc, char **argv)
{
	sim->num_philos = ft_atoi(argv[1]);
	sim->time_death = ft_atoi(argv[2]);
	sim->time_eat = ft_atoi(argv[3]);
	sim->time_sleep = ft_atoi(argv[4]);

	sim->target_eats = 0;
	if (argc == 6)
		sim->target_eats = ft_atoi(argv[5]);
}
static int	errors_in_parameters(t_sim sim)
{
	if (sim.time_sleep < 0 || sim.target_eats < 0 
		|| sim.time_death < 0 || sim.time_eat < 0
		  || sim.num_philos < 1 )
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (argc < 5 || argc > 6)
		return (1);
	set_simulation_parameters(&sim, argc, argv);
	if (errors_in_parameters(sim))
		return (1);
	sim_init(&sim);
	sim_loop(&sim);
	sim_free(&sim);
	return (0);
}
