/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:05:30 by afontain          #+#    #+#             */
/*   Updated: 2023/10/27 16:22:17 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int thinking(t_philo *philo, t_data *data)
{	
	int i;

	i = philo->num;
	if (!is_dead(data, i))
		return (1);
	return (0);
}

int sleeping(t_philo *philo, t_data *data)
{
	int i;
	
	i = philo->num;
	if (!is_dead(philo, i))
		return (printf("%lld Philo %i is sleeping\n", time, i));
	ft_usleep(data->args.t_sleep);
	return (0);
}

int eating(t_philo *philo, t_data *data)
{
	take_fork(philo, data);
	pthread_mutex_lock(&data->time);
	philo->t_die = get_time();
	pthread_mutex_unlock(&data->time);
	pthread_mutex_lock(&data->meal);
	philo->n_meal++;
	pthread_mutex_unlock(&data->meal);
	return (0);
}

int take_fork(t_philo *philo, t_data *data)
{
	int i;

	i = philo->num;
	pthread_mutex_lock(&data->philo->fork_D);
	pthread_mutex_lock(&data->philo->fork_G);
	ft_usleep(data->args.t_eat);
	printf("%lld Philo %i is eating\n", time, i);
	pthread_mutex_unlock(&data->philo->fork_D);
	pthread_mutex_unlock(&data->philo->fork_G);
	return (0);
}
