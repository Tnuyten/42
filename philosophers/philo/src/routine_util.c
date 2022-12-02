/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:14:05 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/28 17:43:58 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// Returns 0 if it is not possible to reserve the fork. Returns 1 if it is.
int	try_reserve_fork(t_philo const *philo, t_fork *fork)
{
	pthread_mutex_lock(philo->setup->fork_states_mtx);
	if (philo->setup->fork_states[fork->num] == 1)
	{
		pthread_mutex_unlock(philo->setup->fork_states_mtx);
		return (0);
	}
	philo->setup->fork_states[fork->num] = 1;
	pthread_mutex_unlock(philo->setup->fork_states_mtx);
	return (1);
}

void	unreserve_fork(t_philo const *philo, t_fork *fork)
{
	pthread_mutex_unlock(fork->mutex);
	pthread_mutex_lock(philo->setup->fork_states_mtx);
	philo->setup->fork_states[fork->num] = 0;
	pthread_mutex_unlock(philo->setup->fork_states_mtx);
}
