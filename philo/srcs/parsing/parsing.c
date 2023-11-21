/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:20:39 by afontain          #+#    #+#             */
/*   Updated: 2023/11/21 18:44:49 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	parsing(int ac, char **av)
{
	(void)av;
	if (ac < 5)
	{
		printf("Tuto:<nb_of_philo> <t_to_die> <t_to_eat> <t_to_sleep>\n");
		return (0);
	}
	else if (ac > 6)
	{
		printf("N'abusons pas des parametres\n");
		return (0);
	}
	return (1);
}

bool	is_positive_int(int ac, char **av)
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
				return (false);
			if (!ft_isdigit(av[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	one_philo(t_data *data, char **av)
{
	long i;

	i = ft_atoi(av[2]);
	data->start = get_time();
	printf("0	1 has taken a fork\n");
	ft_usleep(i);
	printf("%ld	1 has died\n", i);
}
