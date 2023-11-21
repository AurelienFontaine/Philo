/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:59:05 by afontain          #+#    #+#             */
/*   Updated: 2023/11/16 12:16:50 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*check_dead(void *arg)
{
	int		i;
	t_data	*data;

	i = 0;
	data = (t_data *)arg;
	if (data->args.nb_meal)
	{
		while (!data->dead && !has_all_eaten(data, i))
			if (is_dead(data, &i))
				return (NULL);
	}
	else
	{
		while (!data->dead)
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
		data->dead = true;
		pthread_mutex_unlock(&data->time);
		pthread_mutex_lock(&data->print);
		printf("%lld Philo %d died\n", get_time_from_start(data->start), *i + 1);
		pthread_mutex_unlock(&data->print);
		return (1);
	}
	ft_usleep(data, 1);
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