/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:49:30 by afontain          #+#    #+#             */
/*   Updated: 2023/11/22 13:48:53 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_error(char *str, int ret_val)
{
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	return (ret_val);
}

int	print_action(t_philo *philo, t_data *data, char *action)
{
	pthread_mutex_lock(&data->print);
	pthread_mutex_lock(&data->stop);
	if (data->dead == true)
	{
		pthread_mutex_unlock(&data->stop);
		pthread_mutex_unlock(&data->print);
		return (1);
	}
	pthread_mutex_unlock(&data->stop);
	printf("%lld	%d%s", get_time_from_start(data->start),
		philo->num + 1, action);
	pthread_mutex_unlock(&data->print);
	return (0);
}
