/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:28:30 by afontain          #+#    #+#             */
/*   Updated: 2023/10/24 16:15:35 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int create_data(t_data *data, int ac, char **av)
{
	t_philo *philo;
	
	data->start = 0;
	data->dead = 0;
	init_args(ac, av);
	init_philo(philo, ac, av);
	if (!(init_fork))
		return (0);
	return (1);
}


void init_args(int ac, char **av)
{
	t_data *data;
	t_args	*args;
	
	args->nb_philo = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_eat = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->nb_meat = ft_atoi(av[5]);
	else 
		args->nb_meat = 0;
}



void init_philo(t_philo *philo, int ac, char **av)
{
	int i;
	
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo[i].is_alive = 0; 
		philo[i].meat = 0; 
		philo[i].t_die = 0;
		philo[i].num = i; 
		i++;
	}
}
