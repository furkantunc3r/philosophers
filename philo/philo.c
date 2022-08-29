/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:51:29 by ftuncer           #+#    #+#             */
/*   Updated: 2022/08/25 10:12:19 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thnk(t_philo *ph)
{
	act_print(ph->attr, ph->tid, "is thinking");
}

void	eat(t_philo *ph)
{
	if (ph->attr->is_dead)
		return ;
	pthread_mutex_lock(&ph->attr->forks[ph->left]);
	act_print(ph->attr, ph->tid, "has taken a fork");
	pthread_mutex_lock(&ph->attr->forks[ph->right]);
	act_print(ph->attr, ph->tid, "has taken a fork");
	act_print(ph->attr, ph->tid, "is eating");
	ph->last_eat = cur_timestamp(0);
	ph->eat_count++;
	my_sleep(ph->attr->eat_time);
	pthread_mutex_unlock(&ph->attr->forks[ph->left]);
	pthread_mutex_unlock(&ph->attr->forks[ph->right]);
}

void	slp(t_philo *ph)
{
	act_print(ph->attr, ph->tid, "is sleeping");
	my_sleep(ph->attr->sleep_time);
}

void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->tid % 2 == 0 && ph->attr->number_ph > 1)
		usleep(15000);
	while (!ph->attr->is_dead)
	{
		eat(ph);
		thnk(ph);
		if (ph->eat_count == ph->attr->optionaln)
		{
			ph->isfull = 1;
			ph->attr->count_full++;
			break ;
		}
		slp(ph);
	}
	return (ph);
}

int	main(int ac, char **av)
{
	t_attr	attr;

	if (ac < 5 || ac >= 7)
	{
		printf("Invalid Argument!\n");
		return (0);
	}
	if (!check_arg(&attr, av) || !ft_isdigit(av))
	{
		printf("enter a number greater than zero\n");
		return (0);
	}
	if (!init_all(av, ac, &attr))
		return (printf("Invalid Argument!\n"));
	exit_launcher(&attr);
	return (1);
}
