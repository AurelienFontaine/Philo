/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:17:31 by afontain          #+#    #+#             */
/*   Updated: 2023/10/25 15:59:27 by afontain         ###   ########.fr       */
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
	int				meat;
	int				t_die;
	bool			is_alive;
	void			*next;
	pthread_mutex_t	fork_G;
	pthread_mutex_t	fork_D;
}	t_philo;

typedef struct s_args
{
	int		nb_philo;
	long	t_die;
	long	t_eat;
	long	t_sleep;
	int		nb_meat;
}	t_args;

typedef struct s_data
{
	t_philo			philo[200];
	t_args			args;
	int				dead;		
	int				start;
}	t_data;

//Main

//Action
void		*routine(void *data);

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
int			one_philo(t_data *data);
bool		is_positive_int(int ac, char **av);
int			parsing(int ac, char **av);

//Utils
int			ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_isdigit(char c);
int			ft_usleep(useconds_t time);
u_int64_t	get_time(void);

#endif