/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:28:30 by afontain          #+#    #+#             */
/*   Updated: 2023/11/22 15:39:05 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_args(t_args *args, int ac, char **av)
{
	args->nb_philo = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_eat = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->nb_meal = ft_atoi(av[5]);
	else
		args->nb_meal = 0;
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->args.nb_philo)
	{
		data->philo[i].datax = 0;
		data->philo[i].n_meal = 0;
		data->philo[i].t_die = 0;
		data->philo[i].thread = 0;
		data->philo[i].datax = data;
		data->philo[i].num = i;
		i++;
	}
}

int	create_data(t_data *data, int ac, char **av)
{
	data->start = 0;
	data->dead = 0;
	init_args(&data->args, ac, av);
	init_philo(data);
	if (init_mutex(data))
		return (1);
	return (0);
}
