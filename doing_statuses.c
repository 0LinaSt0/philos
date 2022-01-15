/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing_statuses.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:55:09 by msalena           #+#    #+#             */
/*   Updated: 2022/01/15 14:58:17 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	do_take_fork(t_philo *phil, char fl)
{
	char	*cust_print;


	if (fl =='L')
		cust_print = "left";
	else
		cust_print = "right";
	if (do_check_die(phil) == DIE)
		return (DIE);
	pthread_mutex_lock(phil->printing);
	printf("time:%ld phil_num:%d has taken a %s fork\n",
			actual_time(phil->t_start),phil->num, cust_print);
	pthread_mutex_unlock(phil->printing);
	if (do_check_die(phil) == DIE)
		return (DIE);
	return (0);
}

int	do_eat(t_philo *phil)
{
	if (do_check_die(phil) == DIE)
		return (DIE);
	gettimeofday(&(phil->t_eat), NULL);
	pthread_mutex_lock(phil->printing);
	printf("time:%ld phil_num:%d is eating\n", actual_time(phil->t_start),phil->num);
	pthread_mutex_unlock(phil->printing);
	return (0);
}

int	do_sleeping(t_philo *phil)
{
	if (do_check_die(phil) == DIE)
		return (DIE);
	pthread_mutex_lock(phil->printing);
	printf("time:%ld phil_num:%d is sleeping\n", actual_time(phil->t_start),phil->num);
	pthread_mutex_unlock(phil->printing);
	ft_usleep(phil->argums->sleep_time);
	if (do_check_die(phil) == DIE)
		return (DIE);
	return (0);
}

int	do_thinking(t_philo *phil)
{
	if (do_check_die(phil) == DIE)
		return (DIE);
	pthread_mutex_lock(phil->printing);
	printf("time:%ld phil_num:%d is thinking\n", actual_time(phil->t_start),phil->num);
	pthread_mutex_unlock(phil->printing);
	return (0);
}

int	do_check_die(t_philo *phil)
{
	if (phil->die_fl == DIE)
	{
		return (DIE);
	}
	return (0);
}
