/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:20:39 by afontain          #+#    #+#             */
/*   Updated: 2023/11/22 15:47:44 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	parsing(int ac, char **av)
{
	(void)av;
	if (ac < 5 || ac > 6)
	{
		printf("Tuto: <nb_philo> <t_die> <t_eat> <t_sleep> + <max_nb_meal>\n");
		return (1);
	}
	else if ((is_positive_int(ac, av)) == 1)
		return (printf("Les args ne sont pas tous des entiers positifs\n"), 2);
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) <= 0)
	{
		printf("Entrez entre 1 et 200 Philo\n");
		return (3);
	}
	return (0);
}

int	is_positive_int(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][0] == '-')
				return (1);
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	one_philo(t_data *data)
{
	data->start = get_time();
	printf("0	1 %s", TAKE_FORK);
	ft_usleep(data, data->args.t_die);
	printf("%ld	1 %s", data->args.t_die, PHILO_DIED);
}
