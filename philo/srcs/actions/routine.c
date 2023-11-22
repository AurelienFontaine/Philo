/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:06:15 by afontain          #+#    #+#             */
/*   Updated: 2023/11/22 16:40:02 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check(t_data *data)
{
	pthread_mutex_lock(&data->stop);
	if (data->dead)
	{
		pthread_mutex_unlock(&data->stop);
		return (1);
	}
	pthread_mutex_unlock(&data->stop);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*datax;
	int		i;

	philo = (t_philo *)arg;
	datax = philo->datax;
	i = 0;
	if (datax->args.nb_meal)
	{
		while (!check(datax) && philo->n_meal < datax->args.nb_meal)
		{
			if (loop(philo, datax))
				return (NULL);
		}
	}
	else
	{
		while (!check(datax))
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
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->stop);
		return (1);
	}
	pthread_mutex_unlock(&data->stop);
	return (0);
}

int	loop(t_philo *philo, t_data *data)
{
	if (should_stop(data))
		return (1);
	if (take_fork(philo, philo->datax))
		return (2);
	if (should_stop(data))
		return (1);
	if (sleeping(philo, philo->datax))
		return (3);
	if (should_stop(data))
		return (1);
	if (thinking(philo, philo->datax))
		return (4);
	if (should_stop(data))
		return (1);
	return (0);
}
