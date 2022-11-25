/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:39:36 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/25 21:28:55 by thibauld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	free_all(t_philo **p, pthread_t *t, t_mutex *f, int n);
static void	finish(t_philo **p, pthread_t *t, t_mutex *f, t_setup *setup);
static int	run_threads(t_setup setup, pthread_t *threads, t_philo **philos);

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

static void	finish(t_philo **p, pthread_t *t, t_mutex *f, t_setup *setup)
{
	int	i;

	i = -1;
	while (++i < setup->n_philos)
		pthread_join(t[i], NULL);
	pthread_mutex_destroy(setup->status_mtx);
	free(setup->status_mtx);
	free_all(p, t, f, setup->n_philos);
}

static int	run_threads(t_setup setup, pthread_t *threads, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < setup.n_philos)
	{
		if (pthread_create(&threads[i], NULL, philosopher, philos[i]) == 1)
		{
			pthread_mutex_lock(setup.status_mtx);
			setup.status = DEAD;
			pthread_mutex_unlock(setup.status_mtx);
			return (1);
		}
	}
	return (0);
}

static int	err(int e, char *msg)
{
	perror(msg);
	return (e);
}

int	main(int argc, char **argv)
{
	t_setup		setup;
	pthread_t	*threads;
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
	if (threads == NULL || forks == NULL || philos == NULL)
		return (err(1, "Allocation error"));
	if (prepare(&setup, &forks, &philos) == 1)
		return (err(1, "Allocation or mutex initialization error"));
	if (run_threads(setup, threads, philos) == 1)
		return (err(1, "Thread initialization error"));
	finish(philos, threads, forks, &setup);
	return (0);
}
