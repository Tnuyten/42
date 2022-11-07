/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:39:36 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/07 19:23:13 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void parse(int argc, char **argv, t_setup *setup)
{
	t_time	time;

	setup->philos = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		setup->meals = ft_atoi(argv[5]);
	else
		setup->meals = -1;
	gettimeofday(&time, NULL);
	setup->start_time = time.tv_sec;
	setup->start_utime = time.tv_usec;
}

int	main(int argc, char **argv)
{
	t_setup		setup;
	pthread_t	*threads;
	int			i;

	t_philo	* anq = malloc(sizeof(t_philo) * 3);

	if (argc != 5 && argc != 6)
	{
		printf("%s\n", "Incorrect number of arguments provided.");
		return (1);
	}
	parse(argc, argv, &setup);
	threads = malloc(sizeof(pthread_t) * setup.philos);
	i = 0;
	while (i < setup.philos)
	{
		philos->num = i;
		pthread_create(&threads[i], NULL, philosopher, philos);
		i++;
	}
	i = 0;
	while (i < setup.philos)
	{
		pthread_join(threads[i], NULL); // behaves like waitpid()
		i++;
		printf("%s\n", "hi");
	}
	i = 0;
	while (i < setup.philos)
		pthread_detach(threads[i++]);

	// while(1)
	// {
	// 	sleep(1);
	// }
	return (0);
}

// General program structure:
	// Parse input.
	// Setup mutexes (mutices?).
	// Start monitoring thread.
	// Start philo threads.
	// That's it?

// https://en.wikipedia.org/wiki/Dining_philosophers_problem