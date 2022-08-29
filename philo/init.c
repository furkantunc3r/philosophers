/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:51:24 by ftuncer           #+#    #+#             */
/*   Updated: 2022/08/24 14:57:03 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_all(char **av, int ac, t_attr *attr)
{
	if (!init_attr(av, ac, attr))
		return (0);
	init_philo(attr);
	init_mutexes(attr);
	init_threads(attr, &routine);
	return (1);
}

int	init_attr(char **av, int ac, t_attr *attr)
{
	attr->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	attr->number_ph = ft_atoi(av[1]);
	attr->die_time = ft_atoi(av[2]);
	attr->eat_time = ft_atoi(av[3]);
	attr->sleep_time = ft_atoi(av[4]);
	attr->optionaln = -1;
	attr->is_dead = 0;
	attr->start_time = cur_timestamp(0);
	if (ac == 6 && !ft_atoi(av[5]))
		return (0);
	else if (ac == 6 && ft_atoi(av[5]))
		attr->optionaln = ft_atoi(av[5]);
	if (!ft_atoi(av[1]) || !ft_atoi(av[2]) \
		|| !ft_atoi(av[3]) || !ft_atoi(av[4]))
		return (0);
	return (1);
}

int	init_philo(t_attr *attr)
{
	int		i;

	i = -1;
	attr->philo = (t_philo *)malloc(sizeof(t_philo) * attr->number_ph);
	while (++i < attr->number_ph)
	{
		attr->philo[i].tid = i;
		attr->philo[i].eat_count = 0;
		attr->philo[i].isfull = 0;
		attr->philo[i].last_eat = cur_timestamp(0);
		attr->philo[i].right = i;
		attr->philo[i].left = (i + attr->number_ph - 1) % attr->number_ph;
		attr->philo[i].attr = attr;
	}
	return (1);
}

int	init_mutexes(t_attr *attr)
{
	int	i;

	i = -1;
	while (++i < attr->number_ph)
	{
		if (pthread_mutex_init(&attr->forks[i], NULL))
			return (0);
	}
	pthread_mutex_init(&attr->print, NULL);
	return (1);
}

int	init_threads(t_attr *attr, void *(*f)(void *))
{
	int			i;

	i = -1;
	while (++i < attr->number_ph)
	{
		if (pthread_create(&attr->philo[i].pth, NULL, f, &attr->philo[i]))
			return (printf("Thread creation failed!"));
	}
	checker(attr);
	return (0);
}
