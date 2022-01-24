#include "philo.h"

static void	eat_time_check(t_philo *phil, int *eat_time)
{
	if (*eat_time && *eat_time != -1)
		(*eat_time)--;
	if (*eat_time == 0 && phil->end_fl != END)
		phil->end_fl = 1;
}

static void	*for_even_philos(t_philo *phil)
{
	usleep(500);
	pthread_mutex_lock(phil->right);
	pthread_mutex_lock(phil->left);
	if (do_take_fork(phil, 'L') == DIE)
		return (NULL);
	if (do_take_fork(phil, 'R') == DIE)
		return (NULL);
	if (do_eat(phil) == DIE)
		return (NULL);
	ft_usleep(phil->argums->eat_time);
	pthread_mutex_unlock(phil->right);
	pthread_mutex_unlock(phil->left);
	return (phil);
}

static void	*for_odd_philos(t_philo *phil)
{
	usleep(300);
	pthread_mutex_lock(phil->left);
	pthread_mutex_lock(phil->right);
	if (do_take_fork(phil, 'R') == DIE)
		return (NULL);
	if (do_take_fork(phil, 'L') == DIE)
		return (NULL);
	if (do_eat(phil) == DIE)
		return (NULL);
	ft_usleep(phil->argums->eat_time);
	pthread_mutex_unlock(phil->left);
	pthread_mutex_unlock(phil->right);
	return (phil);
}

void	*philo_threads(void *struct_)
{
	t_philo	*phil;
	int		eat_time;

	phil = (t_philo *)struct_;
	eat_time = phil->argums->how_much_eats;
	while (phil->end_fl != END)
	{
		if (do_thinking(phil) == DIE)
			return (NULL);
		if ((phil->num % 2) != 0)
		{
			// usleep(300);
			// pthread_mutex_lock(phil->left);
			// pthread_mutex_lock(phil->right);
			// if (do_take_fork(phil, 'R') == DIE)
			// 	return (NULL);
			// if (do_take_fork(phil, 'L') == DIE)
			// 	return (NULL);
			// if (do_eat(phil) == DIE)
			// 	return (NULL);
			// ft_usleep(phil->argums->eat_time);
			// pthread_mutex_unlock(phil->left);
			// pthread_mutex_unlock(phil->right);
			if (!for_odd_philos(phil))
				return (NULL);
		}
		else
		{
			// usleep(500);
			// pthread_mutex_lock(phil->right);
			// pthread_mutex_lock(phil->left);
			// if (do_take_fork(phil, 'L') == DIE)
			// 	return (NULL);
			// if (do_take_fork(phil, 'R') == DIE)
			// 	return (NULL);
			// if (do_eat(phil) == DIE)
			// 	return (NULL);
			// ft_usleep(phil->argums->eat_time);
			// pthread_mutex_unlock(phil->right);
			// pthread_mutex_unlock(phil->left);
			if (!for_even_philos(phil))
				return (NULL);
		}
		if (do_sleeping(phil) == DIE)
			return (NULL);
		// if (eat_time && eat_time != -1)
		// 	eat_time--;
		// if (eat_time == 0 && phil->end_fl != END)
		// 	phil->end_fl = 1;
		eat_time_check(&eat_time, phil);
	}
	phil->end_fl = 3;
	return (phil);
}
