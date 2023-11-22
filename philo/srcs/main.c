/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:16:16 by afontain          #+#    #+#             */
/*   Updated: 2023/11/22 15:48:19 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac, av) != 0)
		return (1);
	if (create_data(&data, ac, av) == 1)
		return (2);
	if (data.args.nb_philo == 1)
		return (one_philo(&data), 0);
	if (init_thread(&data))
		return (3);
	destroyer(&data, data.args.nb_philo);
	return (0);
}
