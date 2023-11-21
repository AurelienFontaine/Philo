/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:06:15 by afontain          #+#    #+#             */
/*   Updated: 2023/11/14 17:46:36 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo *philo;
	t_data	*datax;

	philo = (t_philo *)arg;
	datax = philo->datax;
	if (datax->args.nb_meal)
	{
		while (!check_dead(datax) && philo->n_meal < datax->args.nb_meal)
		{
			if (loop(philo, datax))
				return (NULL);
		}
	}
	else
	{
		while (!(check_dead(datax)))
		{
			if (loop(philo, datax))
				return (NULL);
		}
	}
	return (NULL);
}

int	should_stop(t_data *data)
{
	pthread_mutex_lock(&data->stop);
	if (data->philo->is_alive == 1)
	{
		pthread_mutex_unlock(&data->stop);
		return (1);
	}
	pthread_mutex_unlock(&data->stop);
	return (0);
}

int loop(t_philo *philo, t_data *data)
{
	if (should_stop(data))
		return (1);
	if (take_fork(philo, data))
		return(2);
	if (should_stop(data))
		return (1);
	if (sleeping(philo, data))
		return (3);
	if (should_stop(data))
		return (1);
	if (thinking(philo, data))
		return (4);
	if (should_stop(data))
		return (1);
	return (0);
}
