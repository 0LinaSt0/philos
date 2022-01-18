/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:55:13 by msalena           #+#    #+#             */
/*   Updated: 2022/01/18 15:18:28 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	Time which was spending from the starting
	of threads time to actual time */
unsigned long	actual_time(struct timeval *start_time)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	if (cur_time.tv_usec >= start_time->tv_usec)
		return ((unsigned long)((cur_time.tv_usec - start_time->tv_usec) / 1000)
			+ (unsigned long)((cur_time.tv_sec - start_time->tv_sec) * 1000));
	else
		return ((unsigned long)((start_time->tv_usec - cur_time.tv_usec) / 1000)
			+ (unsigned long)((cur_time.tv_sec - start_time->tv_sec) * 1000));
}

long	tmp_micsec_AT(struct timeval *start_time)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	return ((unsigned long)(cur_time.tv_usec - start_time->tv_usec)
			+ (unsigned long)((cur_time.tv_sec - start_time->tv_sec) * 1000000));
}

void	ft_usleep(int mlsec)
{
	struct timeval	star_platinum;
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	gettimeofday(&star_platinum, NULL);
	while ((actual_time(&star_platinum) - actual_time(&cur_time)) < (unsigned long)mlsec)
	{
		usleep (100);
		gettimeofday(&cur_time, NULL);
	}
}
