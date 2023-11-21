/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:37:37 by afontain          #+#    #+#             */
/*   Updated: 2023/11/15 17:43:11 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eating(t_philo *philo, t_data *data)
{
	if (print_action(philo, data, EAT))
		return (pthread_mutex_unlock(philo->forkG),
			pthread_mutex_unlock(philo->forkD), 1);
	pthread_mutex_lock(&data->time);
	philo->t_die = get_time();
	pthread_mutex_unlock(&data->time);
	ft_usleep(data, data->args.t_eat);
	pthread_mutex_unlock(philo->forkG);
	pthread_mutex_unlock(philo->forkD);
	pthread_mutex_lock(&data->meal_check);
	philo->n_meal++;
	pthread_mutex_unlock(&data->meal_check);
	return (0);
}

int	take_fork(t_philo *philo, t_data *data)
{
	if (philo->num == 0)
	{
		pthread_mutex_lock(philo->forkD);
		if (print_action(philo, data, TAKE_FORK))
			return (pthread_mutex_unlock(philo->forkD), 1);
		pthread_mutex_lock(philo->forkG);
		if (print_action(philo, data, TAKE_FORK))
			return (pthread_mutex_unlock(philo->forkD),
				pthread_mutex_unlock(philo->forkG), 1);
	}
	else
	{
		pthread_mutex_lock(philo->forkG);
		if (print_action(philo, data, TAKE_FORK))
			return (pthread_mutex_unlock(philo->forkG), 1);
		pthread_mutex_lock(philo->forkD);
		if (print_action(philo, data, TAKE_FORK))
			return (pthread_mutex_unlock(philo->forkG),
				pthread_mutex_unlock(philo->forkD), 1);
	}
	return (eating(philo, data));
}

int	sleeping(t_philo *philo, t_data *data)
{
	if (print_action(philo, data, SLEEP))
		return (1);
	ft_usleep(data, data->args.t_sleep);
	return (0);
}

int	thinking(t_philo *philo, t_data *data)
{
	if (print_action(philo, data, THINK))
		return (1);
	return (0);
}