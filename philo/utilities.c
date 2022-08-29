/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:51:33 by ftuncer           #+#    #+#             */
/*   Updated: 2022/08/24 14:55:14 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *ptr)
{
	long	number;
	int		isnegative;
	int		delimiter;

	number = 0;
	isnegative = 1;
	delimiter = 0;
	if (*ptr == '-')
		return (0);
	if (*ptr == '+')
		delimiter++;
	while (*ptr)
	{
		if (!(*ptr >= 48 && *ptr <= 57))
			return (0);
		number = number * 10 + (*(ptr++) - 48);
		delimiter++;
	}
	number = number * isnegative;
	if (number > 2147483647 || number < -2147483648 || delimiter > 11)
		return (0);
	return ((int)number);
}

long long	cur_timestamp(long long time)
{
	static struct timeval	te;
	long long				milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = (te.tv_sec * 1000 + te.tv_usec / 1000) - time;
	return (milliseconds);
}

void	my_sleep(long long time)
{
	long long	now;

	now = cur_timestamp(0);
	while (cur_timestamp(0) - now < time)
		usleep(100);
}
