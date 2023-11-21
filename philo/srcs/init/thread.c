/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:12:45 by afontain          #+#    #+#             */
/*   Updated: 2023/11/14 17:41:54 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int init_thread(t_data *data)
{
	int	i;

	i = 0;
	data->start = get_time();
	if (pthread_create(&data->check, NULL, check_dead, (void *)data))
		return (error("Error thread", data), 1);
	while (i < data->args.nb_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine,
				(void *)&data->philo[i]))
			return (error("Error thread", data), 2);
		i += 2;
		if (i >= data->args.nb_philo && i % 2 == 0)
		{
			i = 1;
			if (data->args.t_eat < data->args.t_die)
				ft_usleep(data->args.t_eat);
			else
				ft_usleep(data->args.t_die / 2);
		}
		usleep(30);
	}
	return (join_threads(data));
}

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_join(data->check, NULL))
		return (printf("Error with thread\n"), 1);
	while (i < data->args.nb_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (printf("Error with thread\n"), 2);
		i++;
	}
	return (0);
}
