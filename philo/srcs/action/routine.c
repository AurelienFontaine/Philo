/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:06:15 by afontain          #+#    #+#             */
/*   Updated: 2023/10/25 17:36:01 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *routine(void *data)
{
	t_philo philo;
	t_data	data;
	
	printf("Philo X is thinking\n");
	printf("Philo X is eating\n");
	printf("Philo X is sleeping\n");
	
	pthread_mutex_lock();

	//Takes forks
	
	ft_usleep(30);
	pthread_mutex_unlock();
	ft_usleep(30);
	pthread_join();
	pthread_mutex_destroy();
}