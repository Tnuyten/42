/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:39:36 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/29 17:42:59 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	run_threads(t_setup *s);
static int	err(int e, char *msg, t_setup *setup);

int	main(int argc, char **argv)
{
	t_setup		setup;

	if (parse(argc, argv, &setup) == -1)
		return (1);
	setup.threads = ft_calloc(sizeof(pthread_t), setup.n_philos);
	setup.forks = ft_calloc(sizeof(t_mutex), setup.n_philos);
	setup.philos = ft_calloc(sizeof(t_philo *), setup.n_philos);
	setup.fork_states = ft_calloc(sizeof(int), setup.n_philos);
	setup.fork_states_mtx = ft_calloc(sizeof(t_mutex), 1);
	setup.status_mtx = ft_calloc(sizeof(t_mutex), 1);
	if (setup.threads == NULL
		|| setup.forks == NULL
		|| setup.philos == NULL
		|| setup.fork_states == NULL
		|| setup.fork_states_mtx == NULL
		|| setup.status_mtx == NULL)
		return (err(1, "Allocation error", &setup));
	if (prepare(&setup) == 1)
		return (err(1, "Allocation or mutex initialization error", &setup));
	if (run_threads(&setup) == 1)
		return (err(1, "Thread initialization error", &setup));
	finish(&setup);
	return (0);
}

static int	run_threads(t_setup *s)
{
	int	i;

	i = -1;
	while (++i < s->n_philos)
	{
		if (pthread_create(&s->threads[i], NULL, philosopher,
				s->philos[i]) == 1)
		{
			pthread_mutex_lock(s->status_mtx);
			s->status = DEAD;
			pthread_mutex_unlock(s->status_mtx);
			return (1);
		}
	}
	return (0);
}

static int	err(int e, char *msg, t_setup *setup)
{
	printf("%s\n", msg);
	cleanup(setup);
	return (e);
}
