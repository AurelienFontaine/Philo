/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:12:45 by afontain          #+#    #+#             */
/*   Updated: 2023/10/25 15:52:28 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int init_thread(t_data *data)
{
	pthread_t tid;
	int	i;

	i = 0;
	while (i < data->args->nb_philo)
	{
		pthread_create(&tid, NULL, &routine, &data);		
	}
}