/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:21:54 by msalena           #+#    #+#             */
/*   Updated: 2022/01/18 13:27:42 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	check_error(int argc, char **argv)
{
	int	i_arr;
	int	i_str;

	i_arr = 1;
	if (argc != 5 && argc != 6)
	{
		printf ("Error arguments: try again with other ones\n");
		return (DIE);
	}
	while (argv[i_arr])
	{
		i_str = 0;
		while (argv[i_arr][i_str])
		{
			if (!ft_isdigit(argv[i_arr][i_str]))
			{
				printf ("Error arguments: try again with other ones\n");
				return (DIE);
			}
			i_str++;
		}
		i_arr++;
	}
	return (END);
}

int	char_to_num(int argc, char **argv, t_argv *argums)
{
	int	i_arr;
	int	i_str;

	i_arr = 0;
	i_str = 0;
	if (check_error(argc, argv) == DIE)
		return (DIE);
	argums->phil_num = ft_atoi(argv[1]);
	if (argums->phil_num == 0)
	{
		printf ("Error arguments: try again with other ones\n");
		return (DIE);
	}
	argums->die_time = ft_atoi(argv[2]);
	argums->eat_time = ft_atoi(argv[3]);
	argums->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		argums->how_much_eats = ft_atoi(argv[5]);
	else
		argums->how_much_eats = -1;
	return (END);
}

void	*start(void *struct_)
{
	t_philo	*phil;
	int		eat_time;

	phil = (t_philo *)struct_;
	eat_time = phil->argums->how_much_eats;
	while (1 && eat_time)
	{
		if (do_thinking(phil) == DIE)
			return (NULL);

			///////////////////
			// if (phil->num == 2)
			// {
			// pthread_mutex_lock(phil->printing);
			//        printf("//////////////time:%lu phil_num:%d die:%d\n",
			// 	          actual_time(phil->t_start),phil->num, phil->die_fl);
			// pthread_mutex_unlock(phil->printing);
			// }
			///////////////////

		if ((phil->num % 2) != 0)
		{
			pthread_mutex_lock(phil->left);
			pthread_mutex_lock(phil->right);
			///////////////////
			// pthread_mutex_lock(phil->printing);
			//        printf("~~~~~~~~~~~~~~~~time:%ld phil_num:%d l_ptr:%p r_ptr:%p\n",
			// 	          tmp_micsec_AT(phil->t_start),phil->num, phil->left, phil->right);
			// pthread_mutex_unlock(phil->printing);
			///////////////////
			if (do_take_fork(phil, 'R') == DIE)
				return (NULL);
			if (do_take_fork(phil, 'L') == DIE)
				return (NULL);
			if (do_eat(phil) == DIE)
				return (NULL);
			ft_usleep(phil->argums->eat_time);
			pthread_mutex_unlock(phil->left);
			pthread_mutex_unlock(phil->right);
			///////////////////
			// pthread_mutex_lock(phil->printing);
			//        printf("_~~~~~~~~~~~time:%ld phil_num:%d l_ptr:%p r_ptr:%p\n",
			// 	          tmp_micsec_AT(phil->t_start),phil->num, phil->left, phil->right);
			// pthread_mutex_unlock(phil->printing);
			///////////////////
		}
		else
		{
			usleep(300);
			pthread_mutex_lock(phil->right);
			usleep(300);
			pthread_mutex_lock(phil->left);
			///////////////////
			// pthread_mutex_lock(phil->printing);
			//        printf("------------------time:%ld phil_num:%d l_ptr:%p r_ptr:%p\n",
			// 	          tmp_micsec_AT(phil->t_start),phil->num, phil->left, phil->right);
			// pthread_mutex_unlock(phil->printing);
			///////////////////
			if (do_take_fork(phil, 'L') == DIE)
				return (NULL);
			if (do_take_fork(phil, 'R') == DIE)
				return (NULL);
			if (do_eat(phil) == DIE)
				return (NULL);
			ft_usleep(phil->argums->eat_time);
			pthread_mutex_unlock(phil->right);
			pthread_mutex_unlock(phil->left);
			///////////////////
			// pthread_mutex_lock(phil->printing);
			//        printf("~~~~~~~~~~~time:%ld phil_num:%d l_ptr:%p r_ptr:%p\n",
			// 	          tmp_micsec_AT(phil->t_start),phil->num, phil->left, phil->right);
			// pthread_mutex_unlock(phil->printing);
			//////////////////
		}
		if (do_sleeping(phil) == DIE)
			return (NULL);
		if (eat_time && eat_time != -1)
		{
			eat_time--;
			// pthread_mutex_lock(phil->printing);
			// printf("~~~~~~~~~~~phil_num:%d t_eat:%d\n",phil->num, eat_time);
			// pthread_mutex_unlock(phil->printing);
		}
	}
	phil->end_fl = 1;
	// pthread_mutex_lock(phil->printing);
	// 	printf("~~~~~~~~~~~phil_num:%d\n",phil->num);
	// pthread_mutex_unlock(phil->printing);
	while (phil->end_fl != END)
	{
		// if (phil->num == 2)
			// printf ("dadadadaa\n");
		usleep (500);
	}
	return (phil);
}

int	main_thread(t_philo *philo)
{
	int	i;
	int	j;
	int	phil_num;

	i = 0;
	j = 0;
	phil_num = (philo + i)->argums->phil_num;
	while (1)
	{
		while (i < phil_num)
		{
			if (actual_time(&((philo + i)->t_eat)) >= (unsigned long)((philo + i)->argums->die_time)
					&& !(philo + i)->come_fl)
			{

				while (j < phil_num)
				{
					(philo + j)->die_fl = DIE;
			///////////////////
			// if ((philo + i)->num == 2 || (philo + i)->num == 4)
			    //    printf("___________time:%lu phil_num:%d\n",
				//           actual_time((philo + i)->argums->t_start),(philo + i)->num);
			///////////////////
					j++;
				}
				// printf ("phil_num:%d   end_fl:%d\n", i, (philo + i)->end_fl);
				if ((philo + i)->end_fl != 1 && (philo + i)->end_fl != END)
				{
					printf("time:%lu phil_num:%d died\n", actual_time(philo->argums->t_start),(philo + i)->num);
					return (DIE);
				}
				j = 0;
			}
			if (!(philo + i)->come_fl && (philo + i)->end_fl == 1)
			{
				// printf ("...time:%lu phil_num:%d\n", actual_time((philo + i)->argums->t_start),(philo + i)->num);
				(philo + i)->come_fl = 1;
				while (j < phil_num && (philo + j)->end_fl == 1)
					j++;
				if (j == phil_num)
				{
					j = 0;
					while (j < phil_num)
						(philo + j++)->end_fl = END;
					return (END);
				}
				j = 0;
			}
			i++;
		}
		ft_usleep (10);
		i = 0;
	}
	return (0);
}

int	open_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->argums->phil_num)
	{
		pthread_create(&(philos + i)->thread, NULL, start, (philos + i));
		pthread_detach((philos + i)->thread);
		i++;
	}
	if (main_thread(philos) == DIE)
	{
		//free all
		return (DIE);
	}
	return (END);
}

int	initialization(t_argv *argums)
{
	struct timeval	cur_time;
	pthread_mutex_t	*mute_arr;
	pthread_mutex_t	print_fl;
	t_philo			*philo_arr;
	int				i;

	i = 0;
	mute_arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * argums->phil_num);
	philo_arr = (t_philo *)malloc(sizeof(t_philo) * argums->phil_num);
	if (!mute_arr || !philo_arr)
	{
		free(mute_arr);
		free(philo_arr);
		return (DIE);
	}
	argums->t_start = &cur_time;
	gettimeofday(&cur_time, NULL);
	pthread_mutex_init(&(mute_arr[i]), NULL);
	philo_arr[i].num = i + 1;
	philo_arr[i].right = &(mute_arr[argums->phil_num - 1]);
	philo_arr[i].left = &(mute_arr[i]);
	philo_arr[i].argums = argums;argums->t_start = &cur_time;
	philo_arr[i].t_eat = cur_time;
	philo_arr[i].die_fl = 0;
	philo_arr[i].end_fl = 0;
	philo_arr[i].come_fl = 0;
	(philo_arr + i)->printing = &print_fl;
	pthread_mutex_init((philo_arr + i)->printing, NULL);
	i++;
	while (i < argums->phil_num)
	{
		pthread_mutex_init(&(mute_arr[i]), NULL);
		(philo_arr + i)->printing = &print_fl;
		pthread_mutex_init((philo_arr + i)->printing, NULL);
		philo_arr[i].num = i + 1;
		philo_arr[i].right = &(mute_arr[i - 1]);
		philo_arr[i].left = &(mute_arr[i]);
		philo_arr[i].argums = argums;
		philo_arr[i].t_eat = cur_time;
		philo_arr[i].die_fl = 0;
		philo_arr[i].end_fl = 0;
		philo_arr[i].come_fl = 0;
		i++;
	}
	if (open_threads(philo_arr) == DIE)
		return (DIE);
	// return (0);
	// for(int i=0; i<argums->phil_num; i++){
	// 	printf("#:%d  -> %p\n", i, mute_arr + i);
	// }
	// for(int i=0; i<argums->phil_num; i++){
	// 	printf("num:%d     ->     R - %p     L - %p\n", philo_arr[i].num, philo_arr[i].right, philo_arr[i].left);
	// }
	return (END);
}

int	main (int argc, char **argv)
{
		t_argv	argums;

	if (char_to_num(argc, argv, &argums) == DIE || initialization(&argums) == DIE)
		return (DIE);

	// printf ("%d\n", argums.phil_num);
	// printf ("%d\n", argums.die_time);
	// printf ("%d\n", argums.eat_time);
	// printf ("%d\n", argums.sleep_time);
	// printf ("%d\n", argums.how_much_eats);
	// while (){
	// 	pthread_mutexattr_init(arr[i]);
	// }0

}
