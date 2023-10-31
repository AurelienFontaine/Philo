/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:05 by afontain          #+#    #+#             */
/*   Updated: 2023/10/31 16:03:33 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int check_dead(t_data *data)
{
	pthread_mutex_lock(&data->stop);
	if(data->philo->is_alive)
	{
		pthread_mutex_unlock(&data->stop);
		return (1);	
	}
	pthread_mutex_unlock(&data->stop);
	return (0);
}

int is_dead(t_data *data, int i)
{	
	long	time;

	time = get_time_from_start(data->philo[i].t_die);
	if (time > data->args.t_die)
	{
		pthread_mutex_lock(&data->time);
		data->philo->is_alive = false;
		pthread_mutex_unlock(&data->time);
		pthread_mutex_lock(&data->print);
		printf("Philo %d is dead\n", i + 1);
		pthread_mutex_unlock(&data->print);
		return (1);
	}
	ft_usleep(30);
	return (0);
}

int	has_all_eaten(t_data *data, int i)
{
	pthread_mutex_lock(&data->meal_check);
	if (data->philo[i].n_meal < data->args.nb_meal)
	{
		pthread_mutex_unlock(&data->meal_check);
		return (0);
	}
	pthread_mutex_unlock(&data->meal_check);
	return (1);
}