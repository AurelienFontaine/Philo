/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:17:31 by afontain          #+#    #+#             */
/*   Updated: 2023/10/31 16:26:29 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <string.h>
# include <stdbool.h>
# include <time.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num;
	int				n_meal;
	int				t_die;
	bool			is_alive;
	void			*next;
	int				time;
	pthread_mutex_t	*fork_G;
	pthread_mutex_t	*fork_D;
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
	t_philo			philo[200];
	t_args			args;
	int				dead;		
	long			start;
	pthread_mutex_t fork[200];
	pthread_mutex_t	meal_check;
	pthread_mutex_t	stop;
	pthread_mutex_t	time;
	pthread_mutex_t	print;
}	t_data;

//Main

//Action
int eating(t_philo *philo, t_data *data);
int sleeping(t_philo *philo, t_data *data);
int take_fork(t_philo *philo, t_data *data);
int thinking(t_philo *philo, t_data *data);
//Routine
// void		*routine(void *data);

//Checker
int check_dead(t_data *data);
int is_dead(t_data *data, int i);
int	has_all_eaten(t_data *data, int i);

//Clear
void		clear_data(t_data *data);
void 		ft_exit(t_data *data);
int			error(char *str, t_data *data);

//Init
	//Data
void		init_args(t_args *args, int ac, char **av);
void		init_philo(t_data *data, char **av);
int			create_data(t_data *data, int ac, char **av);
	//Mutex
int			init_fork(t_data *data);
	//Thread
int 		init_thread(t_data *data);

//Parsing
void		one_philo(t_data *data);
bool		is_positive_int(int ac, char **av);
int			parsing(int ac, char **av);

//Time
int			ft_usleep(long time);
long long	get_time(void);
long long	get_time_from_start(long long time_to_wait);

//Utils
int			ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_isdigit(char c);

#endif