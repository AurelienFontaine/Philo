/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:19:26 by afontain          #+#    #+#             */
/*   Updated: 2023/10/25 12:56:23 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	signe;

	i = 0;
	nb = 0;
	signe = 1;
	if (str == NULL)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' ' && str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * signe);
}

//usleep with better precision
int	ft_usleep(useconds_t time)
{
	u_int64_t	start;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return(0);
}

//Take the current time in ms
u_int64_t	get_time(void)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		return (error("gettimeofday() FAILURE\n", NULL));
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}
