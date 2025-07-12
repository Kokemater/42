
#define UNLOCK_L 0b1
#define UNLOCK_R 0b10

int	check_dead(t_philo *p)
{
	if (!p->dead && p->last_eat < (timestamp_ms() - p->s->time_to_death))
	{
		print_status(p, "died");
		p->dead = 1;
		p->s->should_end = 1;
		return (1);
	}
	return (0);
}

static int	should_end(t_philo *d, int unlock)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&d->s->check_mutex);
	if (d->s->should_end)
	{
		ret = 1;
		if (unlock & UNLOCK_L)
			pthread_mutex_unlock(d->lfork);
		if (unlock & UNLOCK_R)
			pthread_mutex_unlock(d->rfork);
	}
	pthread_mutex_unlock(&d->s->check_mutex);
	return (ret);
}

static int	take_forks(t_philo *d)
{
	if (should_end(d, 0))
		return (0);
	pthread_mutex_lock(d->lfork);
	if (should_end(d, UNLOCK_L))
		return (0);
	print_status(d, "has taken a fork");
	if (d->s->num_philos == 1)
		return (0);
	pthread_mutex_lock(d->rfork);
	if (should_end(d, UNLOCK_L | UNLOCK_R))
		return (0);
	print_status(d, "has taken a fork");
	return (1);
}

static int	eat(t_philo *d)
{
	print_status(d, "is eating");
	pthread_mutex_lock(&d->s->check_mutex);
	d->last_eat = timestamp_ms();
	d->num_eats++;
	pthread_mutex_unlock(&d->s->check_mutex);
	usleep(d->s->time_to_eat * 1000);
	pthread_mutex_unlock(d->lfork);
	pthread_mutex_unlock(d->rfork);
	return (!should_end(d, 0));
}

void	*philo_func(void *arg)
{
	t_philo	*d;

	d = (t_philo *)arg;
	if (d->idx % 2 == 0)
		usleep(d->s->num_philos * 1000);
	while (1)
	{
		if (!take_forks(d))
			break ;
		if (!eat(d))
			break ;
		print_status(d, "is sleeping");
		usleep(d->s->time_to_sleep * 1000);
		if (should_end(d, 0))
			break ;
		print_status(d, "is thinking");
	}
	return (0);
}
