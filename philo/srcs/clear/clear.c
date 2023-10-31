/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:11:19 by afontain          #+#    #+#             */
/*   Updated: 2023/10/31 16:10:12 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	clear_data(t_data *data)
{
	if (data->philo)
		free(data->philo);
	pthread_mutex_destroy(&data->meal_check);
	pthread_mutex_destroy(&data->stop);
	pthread_mutex_destroy(&data->time);
	pthread_mutex_destroy(&data->print);
}

void ft_exit(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo->num)
		pthread_mutex_destroy(&data->fork[i]);
	clear_data(data);
}

int error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_exit(data);
	return (1);
}
