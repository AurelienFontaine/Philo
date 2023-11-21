/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:11:42 by afontain          #+#    #+#             */
/*   Updated: 2023/11/14 17:24:51 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->print, NULL))
		return (printf("Mutex init error\n"), 1);
	if (pthread_mutex_init(&data->stop, NULL))
		return (pthread_mutex_destroy(&data->print), error("Mutex init error\n", data), 2);
	if (pthread_mutex_init(&data->time, NULL))
		return (pthread_mutex_destroy(&data->print),
			pthread_mutex_destroy(&data->stop), error("Mutex init error\n", data), 3);
	if (pthread_mutex_init(&data->meal_check, NULL))
		return (pthread_mutex_destroy(&data->print),
			pthread_mutex_destroy(&data->stop),
			pthread_mutex_destroy(&data->time), error("Mutex init error\n", data), 4);
	return (init_fork(data));
}

int init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.nb_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (destroyer(data, i), error("Mutex init", data));
		usleep(100);
		i++;
	}
	i = 0;
	while (i < data->args.nb_philo)
	{
		data->philo[i].fork_G = &data->fork[i];
		if (i == data->args.nb_philo - 1)
			data->philo[i].fork_D = &data->fork[0];
		else
			data->philo[i].fork_D = &data->fork[i + 1];
		i++;
	}
	return (0);
}

void	destroyer(t_data *data, int n)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->meal_check);
	pthread_mutex_destroy(&data->time);
	pthread_mutex_destroy(&data->stop);
	while (i < n)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
}
