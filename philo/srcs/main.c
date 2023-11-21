/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:16:16 by afontain          #+#    #+#             */
/*   Updated: 2023/11/13 17:32:38 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char **av)
{
	t_data data;
	
	if (parsing(ac, av) != 0)
	{
		if (!(is_positive_int(ac, av)) == true)
			return (printf("Les arguments ne sont pas tous des entiers positifs\n"), 1);
		return (0);
	}
	if (ft_atoi(av[1]) == 1)
		return (one_philo(&data, av), 0);
	if (create_data(&data, ac, av) == 1)
		return (2);
	if (init_thread(&data))
		return (3);
	destroyer(&data, data.args.nb_philo);
	return (0);
}
