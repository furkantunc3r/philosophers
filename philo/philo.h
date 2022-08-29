/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:51:05 by ftuncer           #+#    #+#             */
/*   Updated: 2022/08/24 15:28:29 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>

typedef struct s_philo	t_philo;

typedef struct s_attr
{
	int				number_ph;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				optionaln;
	int				count_full;
	int				is_dead;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_philo			*philo;
}	t_attr;

typedef struct s_philo
{
	int				tid;
	int				isfull;
	int				meals;
	int				left;
	int				right;
	int				eat_count;
	long long		last_eat;
	pthread_t		pth;
	t_attr			*attr;
}	t_philo;

// init
int			init_all(char **av, int ac, t_attr *attr);
int			init_attr(char **av, int ac, t_attr *attr);
int			init_philo(t_attr *attr);
int			init_mutexes(t_attr *attr);
int			init_threads(t_attr *attr, void *(*f)(void *));

// life cycle
void		*routine(void *ph);
void		*checker(void *atr);

// utils
int			ft_atoi(char *ptr);
long long	cur_timestamp(long long time);
void		my_sleep(long long time);
void		act_print(t_attr *attr, int id, char *string);
void		exit_launcher(t_attr *rules);
int			check_arg(t_attr *attr, char **arg);
int			ft_isdigit(char **arg);

#endif