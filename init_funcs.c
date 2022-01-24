/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:53:59 by msalena           #+#    #+#             */
/*   Updated: 2022/01/24 19:55:07 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos_structs2(pthread_mutex_t *mute_arr,
			pthread_mutex_t *print_fl, t_philo *phil, int *i)
{
	gettimeofday(&phil[*i].t_eat, NULL);
	phil[*i].num = (*i) + 1;
	phil[*i].left = &(mute_arr[*i]);
	phil[*i].printing = print_fl;
	phil[*i].die_fl = 0;
	phil[*i].end_fl = 0;
	phil[*i].come_fl = 0;
	(*i)++;
}

static int	init_philos_structs1(pthread_mutex_t *mute_arr,
			pthread_mutex_t *print_fl, t_philo *phil, t_argv *argums)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(mute_arr[i]), NULL) != 0)
		return (DIE);
	phil[i].right = &(mute_arr[argums->phil_num - 1]);
	phil[i].argums = argums;
	init_philos_structs2(mute_arr, print_fl, phil, &i);
	while (i < argums->phil_num)
	{
		if (pthread_mutex_init(&(mute_arr[i]), NULL) != 0)
			return (DIE);
		phil[i].right = &(mute_arr[i - 1]);
		phil[i].argums = argums;
		init_philos_structs2(mute_arr, print_fl, phil, &i);
	}
	return (i);
}

int	init(t_argv *arg)
{
	struct timeval	*cur_time;
	pthread_mutex_t	*mute_arr;
	pthread_mutex_t	*print_fl;
	t_philo			*philo_arr;
	int				elem_num;

	print_fl = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	mute_arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* arg->phil_num);
	philo_arr = (t_philo *)malloc(sizeof(t_philo) * arg->phil_num);
	cur_time = (struct timeval *)malloc(sizeof(struct timeval));
	if (!cur_time || !mute_arr || !philo_arr || !print_fl
		|| (pthread_mutex_init(print_fl, NULL) != 0))
	{
		free_arrs(cur_time, mute_arr, print_fl, philo_arr);
		return (DIE);
	}
	gettimeofday(cur_time, NULL);
	arg->t_start = cur_time;
	elem_num = init_philos_structs1(mute_arr, print_fl, philo_arr, arg);
	if (elem_num != DIE)
		open_threads(philo_arr);
	free_destroy_mutexs(mute_arr, elem_num);
	free_all(cur_time, mute_arr, print_fl, philo_arr);
	return (END);
}
