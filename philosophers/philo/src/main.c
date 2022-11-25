/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:39:36 by tnuyten           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/24 23:56:56 by tnuyten          ###   ########.fr       */
=======
/*   Updated: 2022/11/15 20:41:44 by tnuyten          ###   ########.fr       */
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

<<<<<<< HEAD
static void	free_all(t_philo **p, pthread_t *t, t_mutex *f, int n);
static void	finish(t_philo **p, pthread_t *t, t_mutex *f, t_setup setup);
static int	run_threads(t_setup setup, pthread_t *threads, t_philo **philos);

=======
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
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

<<<<<<< HEAD
static void	finish(t_philo **p, pthread_t *t, t_mutex *f, t_setup setup)
{
	int	 i;

	i = -1;
	while (++i < setup.n_philos)
		pthread_join(t[i], NULL);
	pthread_mutex_destroy(setup.status_mtx);
	free(setup.status_mtx);
	free_all(p, t, f, setup.n_philos);
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
		// printf("Thread[%d]: 0x%X   -   0x%X\n", i, &threads[i], threads[i]);
	}
	return (0);
}

static int	err(int e, char *msg)
{
	perror(msg);
	return (e);
=======
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
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
}

int	main(int argc, char **argv)
{
	t_setup		setup;
	pthread_t	*threads;
<<<<<<< HEAD
=======
	int			i;
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
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
<<<<<<< HEAD

	// printf("status: %p\n", &setup.status);
	// printf("Threads: 0x%p\n", threads);

	if (threads == NULL || forks == NULL || philos == NULL)
		return (err(1, "Allocation error"));
	if (prepare(&setup, &forks, &philos) == 1)
		return (err(1, "Allocation or mutex initialization error"));
	if (run_threads(setup, threads, philos) == 1)
		return (err(1, "Thread initialization error"));
	finish(philos, threads, forks, setup);
=======
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
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
	return (0);
}
