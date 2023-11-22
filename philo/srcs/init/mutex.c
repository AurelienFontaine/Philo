/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:11:42 by afontain          #+#    #+#             */
/*   Updated: 2023/11/22 11:38:23 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->print, NULL))
		return (print_error(MUTEX_INIT, 1));
	if (pthread_mutex_init(&data->stop, NULL))
		return (pthread_mutex_destroy(&data->print),
			print_error(MUTEX_INIT, 2));
	if (pthread_mutex_init(&data->time, NULL))
		return (pthread_mutex_destroy(&data->print),
			pthread_mutex_destroy(&data->stop), print_error(MUTEX_INIT, 3));
	if (pthread_mutex_init(&data->meal_check, NULL))
		return (pthread_mutex_destroy(&data->print),
			pthread_mutex_destroy(&data->stop),
			pthread_mutex_destroy(&data->time), print_error(MUTEX_INIT, 4));
	return (init_fork(data));
}

int	init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.nb_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (destroyer(data, i), print_error(MUTEX_INIT, 5));
		usleep(100);
		i++;
	}
	i = 0;
	while (i < data->args.nb_philo)
	{
		data->philo[i].forkg = &data->fork[i];
		if (i == data->args.nb_philo - 1)
			data->philo[i].forkd = &data->fork[0];
		else
			data->philo[i].forkd = &data->fork[i + 1];
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
