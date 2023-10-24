/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:16:16 by afontain          #+#    #+#             */
/*   Updated: 2023/10/24 16:21:18 by afontain         ###   ########.fr       */
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
	if (ft_atoi(av[1]) == 1)
		return (one_philo(ac, av));
	if (create_data(data, ac, av) == 1)
		return (1);
	// philo(ac, av);
}
