/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:21:54 by msalena           #+#    #+#             */
/*   Updated: 2022/09/11 21:02:29 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	death_check(t_philo *philo, int *i)
{
	int		j;
	int		phil_num;
	long	time;

	j = 0;
	phil_num = (philo + *i)->argums->phil_num;
	if (actual_time(&((philo + *i)->t_eat)) >= ((philo + *i)->argums->die_time)
		&& !((philo + *i)->come_fl))
	{
		while (j < phil_num)
		{
			(philo + j++)->die_fl = DIE;
		}
		time = actual_time(philo->argums->t_start);
		if ((philo + *i)->end_fl != 1 && (philo + *i)->end_fl != END)
		{
			printf("time:%ld phil_num:%d died\n", time, (philo + *i)->num);
			return (DIE);
		}
	}
	return (END);
}

static int	end_eating_check(t_philo *philo, int *i)
{
	int	j;
	int	phil_num;

	j = 0;
	phil_num = (philo + *i)->argums->phil_num;
	if ((philo + *i)->end_fl == 1 && !((philo + *i)->come_fl))
	{
		(philo + *i)->come_fl = 1;
		while (j < phil_num && (philo + j)->end_fl == 1)
			j++;
		if (j == phil_num)
		{
			j = 0;
			while (j < phil_num)
			{
				(philo + j)->end_fl = END;
				j++;
			}
			return (all_ened_check(philo, 'e'));
			return (DIE);
		}
	}
	return (0);
}

int	main_thread(t_philo *philo)
{
	int	i;
	int	phil_num;

	i = 0;
	phil_num = (philo + i)->argums->phil_num;
	while (1)
	{
		while (i < phil_num)
		{
			if (death_check(philo, &i) == DIE)
				return (DIE);
			if (end_eating_check(philo, &i) == END)
				return (END);
			i++;
		}
		usleep (10);
		i = 0;
	}
	return (END);
}

int	open_threads(t_philo *philos)
{
	int	i;
	int	break_fl;

	break_fl = 0;
	i = 0;
	while (i < philos->argums->phil_num)
	{
		if (pthread_create(&(philos + i)->thread, NULL, philo_threads,
				(philos + i)) != 0 || pthread_detach((philos + i)->thread) != 0)
		{
			break_fl = 1;
			break ;
		}
		i++;
	}
	if (!break_fl)
		main_thread(philos);
	return (END);
}

int	main(int argc, char **argv)
{
	t_argv	*argums;

	argums = (t_argv *)malloc(sizeof(t_argv));
	if (!argums)
		return (DIE);
	if (char_to_num(argc, argv, argums) != DIE)
	{
		init(argums);
	}
	else
		printf ("Error arguments: try again with other ones\n");
	free(argums);
	return (DIE);
}

