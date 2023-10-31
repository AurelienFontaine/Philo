/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:04:14 by afontain          #+#    #+#             */
/*   Updated: 2023/10/31 15:23:20 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_usleep(long time)
{
	long	start;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return(0);
}

long long	get_time(void)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		return (error("gettimeofday() FAILURE\n", NULL));
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

// unsigned long	get_time(t_philo *philo)
// {
// 	unsigned long time;

// 	gettimeofday(&philo->time.cmp, NULL);
// 	time = (philo->time.cmp.tv_sec - philo->time.start.tv_sec) * 1000
// 		+ (philo->time.cmp.tv_usec - philo->time.start.tv_usec) / 1000;
// 	return (time);
// }

long long	get_time_from_start(long long time_to_wait)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (time_to_wait > 0)
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - time_to_wait);
	return (0);
}