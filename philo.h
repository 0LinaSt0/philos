/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:03:52 by msalena           #+#    #+#             */
/*   Updated: 2022/09/11 21:02:11 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define DIE -1
# define END 2

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft/libft.h"

/*ARGUMENTS:
	number_of_philosophers
	time_to_die
	time_to_eat
	time_to_sleep
	[number_of_times_each_philosopher_must_eat]
*/

typedef struct s_argv
{
	int				phil_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				how_much_eats;
	struct timeval	*t_start;
}					t_argv;

typedef struct s_philo
{
	int				num;
	pthread_t		thread;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	pthread_mutex_t	*printing;
	t_argv			*argums;
	struct timeval	t_eat;
	int				die_fl;
	int				end_fl;
	int				come_fl;
}					t_philo;

/*philos_threads*/

int				open_threads(t_philo *philos);
int				main_thread(t_philo *philo);

/*init_funcs*/

int				init(t_argv *argums);

/*philos_threads*/

void			*philo_threads(void *struct_);

/*doing_statuses*/

int				do_take_fork(t_philo *phil, char fl);
int				do_eat(t_philo *phil);
int				do_sleeping(t_philo *phil);
int				do_thinking(t_philo *phil);
int				do_check_die(t_philo *phil);

/*utils*/

int				check_error(int argc, char **argv);
int				char_to_num(int argc, char **argv, t_argv *argums);
long			actual_time(struct timeval *start_time);
void			ft_usleep(int mlsec);
int				all_ened_check(t_philo *philo, char fl);

/*free_funcs*/

void			free_arrs(struct timeval *cur_time, pthread_mutex_t *mute_arr,
					pthread_mutex_t *print_fl, t_philo *philo_arr);
void			free_destroy_mutexs(pthread_mutex_t *mute_arr, int c);
void			free_all(struct timeval *cur_time, pthread_mutex_t *mute_arr,
					pthread_mutex_t *print_fl, t_philo *philo_arr);
#endif
