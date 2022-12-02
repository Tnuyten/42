/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibauld <thibauld@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:29:14 by thibauld          #+#    #+#             */
/*   Updated: 2022/12/02 18:41:04 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "limits.h"
#define IM1000 2147483

static int	err_and_return(int err);

int	parse(int argc, char **argv, t_setup *setup)
{
	t_time	time;

	if (argc != 5 && argc != 6)
	{
		printf("%s\n", "Incorrect number of arguments for philosophers.");
		return (-1);
	}
	setup->n_philos = ft_atoi(argv[1]);
	setup->time_to_die_ms = ft_atoi(argv[2]);
	setup->time_to_eat_ms = ft_atoi(argv[3]);
	setup->time_to_sleep_ms = ft_atoi(argv[4]);
	if (argc == 6)
		setup->courses = ft_atoi(argv[5]);
	else
		setup->courses = -1;
	if (setup->time_to_die_ms > IM1000 || setup->time_to_eat_ms > IM1000
		|| setup->time_to_sleep_ms > IM1000 || setup->n_philos > 200)
		return (err_and_return(-1));
	gettimeofday(&time, NULL);
	setup->start_time = time.tv_sec;
	setup->start_utime = time.tv_usec;
	setup->status = ALIVE;
	return (0);
}

static int	err_and_return(int err)
{
	char	*s2;

	printf("%s\n", "Number entered too large.");
	s2 = "(INT_MAX / 1000)";
	printf("%s %d %s\n", "Max time input:", IM1000, s2);
	printf("%s\n", "Max philosphers: 200");
	return (err);
}

int	prepare(t_setup *setup)
{
	int	i;

	if (pthread_mutex_init(setup->status_mtx, NULL) == 1)
		return (1);
	if (pthread_mutex_init(setup->fork_states_mtx, NULL) == 1)
		return (1);
	i = -1;
	while (++i < setup->n_philos)
	{
		if (pthread_mutex_init(&(setup->forks)[i], NULL) == 1)
			return (1);
	}
	i = -1;
	while (++i < setup->n_philos)
	{
		setup->philos[i] = philo_new(i, setup);
		if (setup->philos[i] == NULL)
			return (1);
	}
	return (0);
}
