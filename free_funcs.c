#include "philo.h"

void	free_arrs(struct timeval *cur_time, pthread_mutex_t *mute_arr,
			pthread_mutex_t *print_fl, t_philo *philo_arr)
{
	free(mute_arr);
	free(philo_arr);
	free(cur_time);
	free(print_fl);
}

void	free_destroy_mutexs(pthread_mutex_t *mute_arr, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		pthread_mutex_destroy(&(mute_arr[i]));
		i++;
	}
}

void	free_all(struct timeval *cur_time, pthread_mutex_t *mute_arr,
			pthread_mutex_t *print_fl, t_philo *philo_arr)
{
	free_destroy_mutexs(mute_arr, i);
	pthread_mutex_destroy(print_fl);
	free_arrs(cur_time, mute_arr, print_fl, philo_arr);
}
