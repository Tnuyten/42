/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:15:35 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/29 17:48:28 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	cleanup(t_setup *setup)
{
	int	i;

	if (setup->philos)
	{
		i = 0;
		while (i < setup->n_philos)
			philo_free(setup->philos[i++]);
		free(setup->philos);
	}
	if (setup->forks)
		free(setup->forks);
	if (setup->threads)
		free(setup->threads);
	if (setup->status_mtx)
	{
		pthread_mutex_destroy(setup->status_mtx);
		free(setup->status_mtx);
	}
	if (setup->fork_states_mtx)
	{
		pthread_mutex_destroy(setup->fork_states_mtx);
		free(setup->fork_states_mtx);
	}
	if (setup->fork_states)
		free(setup->fork_states);
}

void	finish(t_setup *setup)
{
	int	i;

	i = -1;
	while (++i < setup->n_philos)
		pthread_join(setup->threads[i], NULL);
	cleanup(setup);
}
