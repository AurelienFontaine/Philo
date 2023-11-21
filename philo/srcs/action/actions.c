/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:05:30 by afontain          #+#    #+#             */
/*   Updated: 2023/11/14 16:52:14 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int thinking(t_philo *philo, t_data *data)
{	
	if (!is_dead(data))
		return (printf("%lld Philo %i is thinking\n", get_time_from_start(data->start), philo->num), 1);
	return (0);
}

int sleeping(t_philo *philo, t_data *data)
{
	if (!is_dead(data))
		return (printf("%lld Philo %i is sleeping\n", get_time_from_start(data->start), philo->num), 1);
	ft_usleep(data->args.t_sleep);
	return (0);
}

int eating(t_philo *philo, t_data *data)
{
	take_fork(philo, data);
	pthread_mutex_lock(&data->time);
	philo->t_die = get_time();
	ft_usleep(data->args.t_die);
	pthread_mutex_unlock(&data->time);
	pthread_mutex_lock(&data->meal_check);
	philo->n_meal++;
	pthread_mutex_unlock(&data->meal_check);
	return (0);
}

int take_fork(t_philo *philo, t_data *data)
{
	if (philo->num == 0)
	{
		pthread_mutex_lock(philo->fork_D);
		pthread_mutex_lock(philo->fork_G);
		printf("%lld Philo %i is eating\n", get_time_from_start(data->start), philo->num);
		pthread_mutex_unlock(philo->fork_D);
		pthread_mutex_unlock(philo->fork_G);
	}
	else
	{
		pthread_mutex_lock(philo->fork_G);
		pthread_mutex_lock(philo->fork_D);
		ft_usleep(data->args.t_eat);
		printf("%lld Philo %i is eating\n", get_time_from_start(data->start), philo->num);
		pthread_mutex_unlock(philo->fork_D);
		pthread_mutex_unlock(philo->fork_G);
	}
	return (0);
}
