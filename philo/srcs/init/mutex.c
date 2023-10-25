/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:11:42 by afontain          #+#    #+#             */
/*   Updated: 2023/10/25 17:04:04 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args->nb_philo)
	{
		
	}
}

int init_mutex(t_data *data)
{
	phtread_mutex_t mutex;
	
	pthread_mutex_init(&mutex, NULL);
	
}

void destroy_mutex(t_data *data)
{
	if ()
	pthread_mutexattr_destroy()
}