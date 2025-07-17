/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:32:15 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/17 11:03:49 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

typedef struct s_philo
{
	pthread_t		thread;
	int				idx;
	long			last_eat;
	int				dead;
	int				num_eats;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	struct s_sim	*s;
}	t_philo;

typedef struct s_sim
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	check_mutex;
	int				num_philos;
	int				sim_should_end;
	int				time_to_eat;
	int				target_eats;
	int				time_to_sleep;
	int				time_to_death;
	long			sim_start;
}	t_sim;

void		*philo_func(void *arg);
int			ft_atoi(const char *str);
long		time_in_ms(void);
int			take_left_then_right(t_philo *phil);
int			take_right_then_left(t_philo *phil);
int			take_forks(t_philo *phil);
void		print_status(t_philo *phil, const char *status);
int			check_dead(t_philo *phil);
int			sim_should_end(t_philo *phil, int unlock_left, int unlock_right);
int			reach_target_eats(int rem, t_sim *s);
void		initialice_simulation(t_sim *simul);
void		loop_simulation(t_sim *simul);

#endif
