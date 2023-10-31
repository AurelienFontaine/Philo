/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:11:42 by afontain          #+#    #+#             */
/*   Updated: 2023/10/31 16:20:06 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int init_fork(t_data *data)
{
	int	i;

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

// int init_mutex(t_data *data)
// {
// 	phtread_mutex_t mutex;
	
// 	if (pthread_mutex_init(&mutex, NULL));
	
	
// }

// void destroy_mutex(t_data *data)
// {
// 	if ()
// 	pthread_mutexattr_destroy()
// }