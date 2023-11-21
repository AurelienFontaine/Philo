/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:05 by afontain          #+#    #+#             */
/*   Updated: 2023/11/14 17:39:40 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*check_dead(void *arg)
{
	int		i;
	t_data	*data;

	i = 0;
	data = (t_data *)arg;
	if (data->args.nb_meal)
	{
		while (data->philo->is_alive && !has_all_eaten(data, i))
			if (is_dead(data, &i))
				return (NULL);
	}
	else
	{
		while (!data->philo->is_alive)
			if (is_dead(data, &i))
				return (NULL);
	}
	return (NULL);
}


int is_dead(t_data *data, int *i)
{	
	long	time;

	if (*i == data->args.nb_philo - 1)
		*i = 0;
	pthread_mutex_lock(&data->time);
	time = get_time_from_start(data->philo[*i].t_die);
	pthread_mutex_unlock(&data->time);
	if (time > data->args.t_die)
	{
		pthread_mutex_lock(&data->time);
		data->philo->is_alive = false;
		pthread_mutex_unlock(&data->time);
		pthread_mutex_lock(&data->print);
		printf("Philo %d is dead\n", *i + 1);
		pthread_mutex_unlock(&data->print);
		return (1);
	}
	ft_usleep(30);
	(*i)++;
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