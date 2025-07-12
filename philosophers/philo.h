/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutragu <jbutragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:32:15 by jbutragu          #+#    #+#             */
/*   Updated: 2025/07/12 13:45:49 by jbutragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

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
	int				num_philos;
	int				should_end;
	int				time_eat;
	int				target_eats;
	int				time_sleep;
	int				time_death;
	long			sim_start;
	t_philo			*philos;
	// pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mut;
	pthread_mutex_t	check_mut;
}	t_sim;

void		*philo_func(void *arg);
int			ft_atoi(const char *str);
long		timestamp_ms(void);
void		print_status(t_philo *d, const char *status);
long		ft_min(long a, long b);
int			check_dead(t_philo *p);
int			target_eats_reached(int rem, t_sim *s);
void		sim_init(t_sim *sim);
void		sim_loop(t_sim *sim);

#endif
