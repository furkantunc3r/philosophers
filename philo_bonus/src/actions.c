/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:30:38 by merkol            #+#    #+#             */
/*   Updated: 2022/08/29 14:00:31 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo *ph)
{
	sem_wait(ph->attr->sem_forks);
	print_msg(ph, "has taken a fork");
	sem_wait(ph->attr->sem_forks);
	print_msg(ph, "has taken a fork");
	print_msg(ph, "is eating");
	ph->last_eat = cur_timestamp(0);
	my_sleep(ph->attr->eat_time);
	ph->c_eat++;
	sem_post(ph->attr->sem_forks);
	sem_post(ph->attr->sem_forks);
}

void	slp(t_philo *ph)
{
	print_msg(ph, "is sleeping");
	my_sleep(ph->attr->sleep_time);
}

void	thnk(t_philo *ph)
{
	print_msg(ph, "is thinking");
}
