/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:55:13 by msalena           #+#    #+#             */
/*   Updated: 2022/09/11 20:37:32 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_error(int argc, char **argv)
{
	int	i_arr;
	int	i_str;

	i_arr = 1;
	if ((argc != 5 && argc != 6))
		return (DIE);
	while (argv[i_arr])
	{
		i_str = 0;
		while (argv[i_arr][i_str])
		{
			if (!ft_isdigit(argv[i_arr][i_str]))
				return (DIE);
			i_str++;
		}
		i_arr++;
	}
	return (END);
}

int	char_to_num(int argc, char **argv, t_argv *argums)
{
	if (check_error(argc, argv) == DIE)
		return (DIE);
	argums->phil_num = ft_atoi(argv[1]);
	if (argums->phil_num == 0)
		return (DIE);
	argums->die_time = ft_atoi(argv[2]);
	argums->eat_time = ft_atoi(argv[3]);
	argums->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		argums->how_much_eats = ft_atoi(argv[5]);
		if (argums->how_much_eats == 0)
			return (DIE);
	}
	else
		argums->how_much_eats = -1;
	return (END);
}

/*	Time which was spending from the starting
	of threads time to actual time */
long	actual_time(struct timeval *start_time)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	return (((cur_time.tv_sec - start_time->tv_sec) * 1000000
			+ ((cur_time.tv_usec - start_time->tv_usec))) / 1000);
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

int	all_ened_check(t_philo *philo, char fl)
{
	int	j;
	int	num;

	j = 0;
	num = (philo + j)->argums->phil_num;
	while (1)
	{
		if (fl == 'e')
		{
			while (j < num && (philo + j)->end_fl == 3)
				j++;
			if (j == num)
				return (END);
		}
		else if (fl == 'd')
		{
			while (j < num && (philo + j)->die_fl == -2)
				j++;
			if (j == num || num == 1)
				return (END);
		}
	}
	return (DIE);
}
