/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:17:31 by afontain          #+#    #+#             */
/*   Updated: 2023/11/22 15:47:39 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//Include
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <string.h>
# include <stdbool.h>
# include <time.h>
# include <pthread.h>
# include <sys/time.h>

// Actions
# define EAT		" is eating\n"
# define SLEEP		" is sleeping\n"
# define THINK		" is thinking\n"
# define TAKE_FORK		" has taken a fork\n"
# define PHILO_DIED		" has died\n"

// Error
# define MALLOC			"Error malloc"
# define MUTEX_INIT		"Error mutex init"
# define DESTRUCT		"Error mutex destruction"
# define THREADS		"Error threads"
# define FORK			"Error fork mutex"

typedef struct s_philo
{
	int				num;
	int				n_meal;
	long			t_die;
	void			*datax;
	pthread_t		thread;
	pthread_mutex_t	*forkg;
	pthread_mutex_t	*forkd;
}	t_philo;

typedef struct s_args
{
	int		nb_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	int		nb_meal;
}	t_args;

typedef struct s_data
{
	bool			dead;		
	long			start;
	t_philo			philo[200];
	t_args			args;
	pthread_t		check;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	meal_check;
	pthread_mutex_t	stop;
	pthread_mutex_t	time;
	pthread_mutex_t	print;
}	t_data;

//Main

//Action
int			eating(t_philo *philo, t_data *data);
int			sleeping(t_philo *philo, t_data *data);
int			take_fork(t_philo *philo, t_data *data);
int			thinking(t_philo *philo, t_data *data);
//Routine
void		*routine(void *data);
int			loop(t_philo *philo, t_data *data);
//Checker
void		*check_dead(void *arg);
int			is_dead(t_data *data, int *i);
int			has_all_eaten(t_data *data, int i);

//Init
	//Data
void		init_args(t_args *args, int ac, char **av);
void		init_philo(t_data *data);
int			create_data(t_data *data, int ac, char **av);
	//Mutex
int			init_fork(t_data *data);
int			init_mutex(t_data *data);
void		destroyer(t_data *data, int n);
	//Thread
int			init_thread(t_data *data);
int			join_threads(t_data *data);

//Parsing
void		one_philo(t_data *data);
int			is_positive_int(int ac, char **av);
int			parsing(int ac, char **av);

//Print
int			print_error(char *str, int ret_val);
int			print_action(t_philo *philo, t_data *data, char *action);

//Time
void		ft_usleep(t_data *data, long int time_in_ms);
long long	get_time(void);
long long	get_time_from_start(long long time_to_wait);

//Utils
int			ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_isdigit(char c);

#endif