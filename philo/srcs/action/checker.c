/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:05 by afontain          #+#    #+#             */
/*   Updated: 2023/10/27 16:14:06 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int check_dead(t_data *data)
{
	pthread_mutex_lock(&data->stop);
	if(data->philo->is_alive)
	{
		ptread_mutex_unlock(data->stop);
		return (1);	
	}
	ptread_mutex_unlock(data->stop);
	return (0);
}

int is_dead(t_data *data, int i)
{	
	long	time;

	time = get_time_from_start(data->philo[i].t_die);
	if (time > data->args.t_die)
	{
		pthread_mutex_lock(&data);
		data->philo->is_alive = false;
		pthread_mutex_unlock(&data);
		pthread_mutex_lock(&data);
		printf("Philo %d is dead\n", i + 1);
		pthread_mutex_unlock(&data);
		return (1);
	}
	ft_usleep(30);
	return (0);
}

int	has_all_eaten(t_data *data, int i)
{
	pthread_mutex_lock(&data->philo->n_meal);
	if (data->philo[i].n_meal < data->args.nb_meal)
	{
		pthread_mutex_unlock(&data->philo->n_meal);
		return (0);
	}
	pthread_mutex_unlock(&data->philo->n_meal);
	return (1);
}