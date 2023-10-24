/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:17:31 by afontain          #+#    #+#             */
/*   Updated: 2023/10/24 16:21:41 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int			num;
	int			meat;
	int			t_die;
	bool		is_alive;
	void		*next;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	*fork;
	int				indice;
	void			*next;
}	t_fork;

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
	t_philo			*philo;
	t_fork			*fork;
	t_args			*args;
	int				dead;		
	int				start;
}	t_data;

//Main


//Parsing
int		one_philo(int ac, char **av);
bool	is_positive_int(int ac, char **av);
int		parsing(int ac, char **av);

//Create
	//Data
void	init_args(int ac, char **av);
void	init_philo(t_philo *philo, int ac, char **av);
int		create_data(t_data *data, int ac, char **av);
	//Mutex
int		init_fork(t_data *data);
	//Thread
int 	init_thread(t_data *data);

//Utils
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_isdigit(char c);

#endif