/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:04:14 by afontain          #+#    #+#             */
/*   Updated: 2023/11/15 17:41:13 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	get_time_from_start(long long time_to_wait)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (time_to_wait > 0)
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - time_to_wait);
	return (0);
}

void	ft_usleep(t_data *data, long int time_in_ms)
{
	long int	start_time;

	start_time = get_time_from_start(data->start);
	while (get_time_from_start(data->start) < start_time + time_in_ms)
	{
		pthread_mutex_lock(&data->stop);
		if (data->dead)
		{
			pthread_mutex_unlock(&data->stop);
			return ;
		}
		pthread_mutex_unlock(&data->stop);
		usleep(time_in_ms / 20);
	}
}
