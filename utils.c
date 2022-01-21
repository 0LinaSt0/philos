/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:55:13 by msalena           #+#    #+#             */
/*   Updated: 2022/01/21 20:20:14 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	Time which was spending from the starting
	of threads time to actual time */
long	actual_time(struct timeval *start_time)
{
	struct timeval	cur_time;
	// long			mic_sec;
	// long			sec;

	gettimeofday(&cur_time, NULL);
	// mic_sec = (long)(cur_time.tv_usec - start_time->tv_usec);
	// sec = (long)(cur_time.tv_sec - start_time->tv_sec);
	// 	return ((mic_sec / 1000) + (sec * 1000));


	// printf("\tcurrent time: %p\n", &cur_time);
	// printf("\tstart time: %p\n", start_time);
	return ((cur_time.tv_sec - start_time->tv_sec) * 1000000 + ((cur_time.tv_usec - start_time->tv_usec))) / 1000;


	// long long sec = (cur_time.tv_sec - start_time->tv_sec) * 1000000;
	// long long usec = cur_time.tv_usec - start_time->tv_usec;
	// return (sec + usec) / 1000;
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
	while ((actual_time(&star_platinum) - actual_time(&cur_time)) < mlsec)
	{
		usleep (500);
		gettimeofday(&cur_time, NULL);
	}
}
