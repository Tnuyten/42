/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:39:36 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/15 20:41:44 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	free_all(t_philo **p, pthread_t *t, t_mutex *f, int n)
{
	int	i;

	i = 0;
	while (i < n)
		philo_free(p[i++]);
	free(p);
	free(f);
	free(t);
}

static void	wait_for_threads(int n, pthread_t *threads)
{
	int	 i;

	i = 0;
	while (i < n)
	{
		// pthread_detach(threads[i]);
		pthread_join(threads[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_setup		setup;
	pthread_t	*threads;
	int			i;
	t_mutex		*forks;
	t_philo		**philos;

	if (argc != 5 && argc != 6)
	{
		printf("%s\n", "Incorrect number of arguments for philosophers.");
		return (1);
	}
	parse(argc, argv, &setup);
	threads = ft_calloc(sizeof(pthread_t), setup.n_philos);
	forks = ft_calloc(sizeof(t_mutex), setup.n_philos);
	philos = ft_calloc(sizeof(t_mutex *), setup.n_philos);
	setup.status_mtx = ft_calloc(sizeof(t_mutex), 1);
	pthread_mutex_init(setup.status_mtx, NULL);
	i = -1;
	while (++i < setup.n_philos)
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < setup.n_philos)
		philos[i] = philo_new(i, &setup, forks);
	i = -1;
	while (++i < setup.n_philos)
		pthread_create(&threads[i], NULL, philosopher, philos[i]);
	wait_for_threads(setup.n_philos, threads);
	free_all(philos, threads, forks, setup.n_philos);
	pthread_mutex_destroy(setup.status_mtx);
	free(setup.status_mtx);
	return (0);
}
