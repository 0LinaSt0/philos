/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:57:38 by msalena           #+#    #+#             */
/*   Updated: 2022/01/24 20:06:05 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (!for_odd_philos(phil))
				return (NULL);
		}
		else
		{
			if (!for_even_philos(phil))
				return (NULL);
		}
		if (do_sleeping(phil) == DIE)
			return (NULL);
		eat_time_check(phil, &eat_time);
	}
	phil->end_fl = 3;
	return (phil);
}
