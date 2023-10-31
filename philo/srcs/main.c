/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:16:16 by afontain          #+#    #+#             */
/*   Updated: 2023/10/31 16:27:06 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int ac, char **av)
{
	t_data *data;
	
	data = NULL;
	if (parsing(ac, av) != 0)
	{
		if (!(is_positive_int(ac, av)) == true)
			return (printf("Les arguments ne sont pas tous des entiers positifs\n"), 0);
	}
	if (create_data(data, ac, av) == 1)
		return (1);
	if (ft_atoi(av[1]) == 1)
		return (one_philo(data), 0);
	// else
	// 	routine(ac, av);
	// ft_exit(data);
}
