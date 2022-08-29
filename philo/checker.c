/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:51:19 by ftuncer           #+#    #+#             */
/*   Updated: 2022/08/24 14:51:20 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker(void *atr)
{
	int		i;
	t_attr	*attr;

	attr = (t_attr *)atr;
	i = 0;
	while (1)
	{
		if (attr->count_full == attr->number_ph)
			break ;
		if (i == attr->number_ph)
			i = 0;
		usleep(100);
		if (!attr->philo[i].isfull \
			&& cur_timestamp(attr->philo[i].last_eat) > attr->die_time)
		{
			act_print(attr, i, "has died");
			attr->is_dead = 1;
			break ;
		}
		i++;
	}
	return (0);
}
