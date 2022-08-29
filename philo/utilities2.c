/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:53:14 by ftuncer           #+#    #+#             */
/*   Updated: 2022/08/25 10:12:40 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	act_print(t_attr *attr, int id, char *string)
{
	pthread_mutex_lock(&attr->print);
	if (!attr->is_dead)
	{
		printf("%lli ", cur_timestamp(0) - attr->start_time);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&attr->print);
	return ;
}

void	exit_launcher(t_attr *rules)
{
	int	i;

	i = -1;
	while (++i < rules->number_ph && rules->number_ph > 1)
		pthread_join(rules->philo[i].pth, NULL);
	i = -1;
	while (++i < rules->number_ph)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->print));
	free(rules->forks);
	free(rules->philo);
}

int	ft_isdigit(char **arg)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arg[i][j])
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(t_attr *attr, char **arg)
{
	attr->number_ph = ft_atoi(arg[1]);
	attr->die_time = ft_atoi(arg[2]);
	attr->eat_time = ft_atoi(arg[3]);
	attr->sleep_time = ft_atoi(arg[4]);
	if (attr->number_ph <= 0)
		return (0);
	else if (attr->die_time <= 0)
		return (0);
	else if (attr->eat_time <= 0)
		return (0);
	else if (attr->sleep_time <= 0)
		return (0);
	else if (arg[5] != NULL)
	{
		attr->optionaln = ft_atoi(arg[5]);
		if (attr->optionaln <= 0)
			return (0);
	}
	return (1);
}
