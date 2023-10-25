/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:11:19 by afontain          #+#    #+#             */
/*   Updated: 2023/10/25 15:28:11 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	clear_data(t_data *data)
{
	if (data->philo)
		free(data->philo);
	if (data->args)
		free(data->args);
}

void ft_exit(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo->num)
		pthread_mutex_destroy(&data->philo[i]);
	clear_data(data);
}

int error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_exit(data);
	return (1);
}
