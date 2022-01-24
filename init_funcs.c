#include "philo.h"

static void	init_philos_structs2(pthread_mutex_t *mute_arr,
			pthread_mutex_t *print_fl, t_philo *philo_arr, int *i)
{
	gettimeofday(&philo_arr[*i].t_eat, NULL);
	philo_arr[*i].num = i + 1;
	philo_arr[*i].left = &(mute_arr[*i]);
	philo_arr[*i].argums = argums;
	philo_arr[*i]->printing = print_fl;
	philo_arr[*i].die_fl = 0;
	philo_arr[*i].end_fl = 0;
	philo_arr[*i].come_fl = 0;
	(*i)++;
}

static int	init_philos_structs1(pthread_mutex_t *mute_arr,
			pthread_mutex_t *print_fl, t_philo *philo_arr)
{
	int	i;

	i = 0;
	philo_arr[i].right = &(mute_arr[argums->phil_num - 1]);
	gettimeofday(&philo_arr[i].t_eat, NULL);
	// philo_arr[i].num = i + 1;
	// philo_arr[i].left = &(mute_arr[i]);
	// philo_arr[i].argums = argums;
	// (philo_arr + i)->printing = print_fl;
	// philo_arr[i].die_fl = 0;
	// philo_arr[i].end_fl = 0;
	// philo_arr[i].come_fl = 0;
	// i++;
	init_philos_structs2(mute_arr, print_fl, philo_arr, &i);
	while (i < argums->phil_num)
	{
		if (pthread_mutex_init(&(mute_arr[i]), NULL) != 0)
			return (DIE);
		philo_arr[i].right = &(mute_arr[i - 1]);
		// gettimeofday(&philo_arr[i].t_eat, NULL);
		// philo_arr[i].num = i + 1;
		// philo_arr[i].left = &(mute_arr[i]);
		// philo_arr[i].argums = argums;
		// (philo_arr + i)->printing = print_fl;
		// philo_arr[i].die_fl = 0;
		// philo_arr[i].end_fl = 0;
		// philo_arr[i].come_fl = 0;
		// i++;
		init_philos_structs2(mute_arr, print_fl, philo_arr, &i);
	}
	return (END);
}

int	init(t_argv *argums)
{
	struct timeval	*cur_time;
	pthread_mutex_t	*mute_arr;
	pthread_mutex_t	*print_fl;
	t_philo			*philo_arr;

	print_fl = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	mute_arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * argums->phil_num);
	philo_arr = (t_philo *)malloc(sizeof(t_philo) * argums->phil_num);
	cur_time = (struct timeval *)malloc(sizeof(struct timeval));
	if (!cur_time || !mute_arr || !philo_arr || !print_fl
			|| (pthread_mutex_init(print_fl, NULL) != 0)
			|| (pthread_mutex_init(&(mute_arr[i]), NULL) != 0))
	{
		free_arrs(cur_time, mute_arr, print_fl, philo_arr);
		return (DIE);
	}
	gettimeofday(cur_time, NULL);
	argums->t_start = cur_time;
	// philo_arr[i].right = &(mute_arr[argums->phil_num - 1]);
	// gettimeofday(&philo_arr[i].t_eat, NULL);
	// philo_arr[i].num = i + 1;
	// philo_arr[i].left = &(mute_arr[i]);
	// philo_arr[i].argums = argums;
	// (philo_arr + i)->printing = print_fl;
	// philo_arr[i].die_fl = 0;
	// philo_arr[i].end_fl = 0;
	// philo_arr[i].come_fl = 0;
	// i++;
	// while (i < argums->phil_num)
	// {
	// 	if (pthread_mutex_init(&(mute_arr[i]), NULL) != 0)
	// 	{
	// 		free_all(cur_time, mute_arr, print_fl, philo_arr);
	// 		return (DIE);
	// 	}
	// 	philo_arr[i].right = &(mute_arr[i - 1]);
	// 	gettimeofday(&philo_arr[i].t_eat, NULL);
	// 	philo_arr[i].num = i + 1;
	// 	philo_arr[i].left = &(mute_arr[i]);
	// 	philo_arr[i].argums = argums;
	// 	philo_arr[i].die_fl = 0;
	// 	philo_arr[i].end_fl = 0;
	// 	philo_arr[i].come_fl = 0;
	// 	(philo_arr + i)->printing = print_fl;
	// 	i++;
	// }
	if ((init_philos_structs1(mute_arr, print_fl, philo_arr)) == END)
		open_threads(philo_arr);
	free_all(cur_time, mute_arr, print_fl, philo_arr);
	return (END);
}
