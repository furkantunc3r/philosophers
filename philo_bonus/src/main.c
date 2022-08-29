/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 00:30:56 by merkol            #+#    #+#             */
/*   Updated: 2022/08/29 14:00:15 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_attr	attr;

	if (ac < 5 || ac >= 7)
		return (printf("Usage: tt_die tt_eat tt_sleep meal_count\n"));
	if (!init_all(av, ac, &attr))
		return (printf("Invalid entry!\n"));
	if (!start_process(&attr))
		return (printf("Unable to create fork!"));
	return (1);
}
