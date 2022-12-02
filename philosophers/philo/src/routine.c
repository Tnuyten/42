/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:14:56 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/29 17:55:58 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	routine(t_philo const *philo, t_fork *fst_fork, t_fork *snd_fork);
static int	eat_and_sleep(t_philo *philo);
static int	check_for_death(t_philo const *philo);
static int	take_fork(t_philo const *philo, t_fork *fork, t_fork *locked_fork);

void	*philosopher(void *arg)
{
	t_philo const	*philo = (t_philo const *)arg;
	int				i;
	int				courses;
	t_fork			*first_fork;
	t_fork			*second_fork;

	first_fork = philo->left_fork;
	second_fork = philo->right_fork;
	if (philo->num % 2 == 0)
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	if (philo->num % 2 == 0)
		usleep(500);
	courses = philo->setup->courses;
	i = 0;
	while (1)
	{
		if (courses != -1 && i++ >= courses)
			break ;
		if (routine(philo, first_fork, second_fork) == 1)
			break ;
	}
	return (NULL);
}

static int	routine(t_philo const *philo, t_fork *fst_fork, t_fork *snd_fork)
{
	philo_print_message_if_alive("is thinking", philo);
	if (philo->setup->n_philos % 2 == 1 && philo->num % 2 == 0)
		sleep_while_not_dead((philo->setup->time_to_eat_ms * 2
				- philo->setup->time_to_sleep_ms) * 950, philo);
	if (take_fork(philo, fst_fork, NULL) == DEAD)
		return (1);
	if (take_fork(philo, snd_fork, fst_fork) == DEAD)
		return (1);
	if (check_for_death(philo) == DEAD)
	{
		pthread_mutex_unlock(philo->left_fork->mutex);
		pthread_mutex_unlock(philo->right_fork->mutex);
		return (1);
	}
	if (eat_and_sleep((t_philo *)philo) == DEAD)
		return (1);
	if (check_for_death(philo) == DEAD)
		return (1);
	return (0);
}

static int	take_fork(t_philo const *philo, t_fork *fork, t_fork *locked_fork)
{
	while (try_reserve_fork(philo, fork) == 0)
	{
		if (check_for_death(philo) == DEAD)
		{
			if (locked_fork != NULL)
				unreserve_fork(philo, locked_fork);
			return (DEAD);
		}
		usleep(100);
	}
	pthread_mutex_lock(fork->mutex);
	if (check_for_death(philo) == DEAD)
	{
		unreserve_fork(philo, fork);
		if (locked_fork != NULL)
			unreserve_fork(philo, locked_fork);
		return (DEAD);
	}
	philo_print_message_if_alive("has taken a fork", philo);
	return (ALIVE);
}

static int	eat_and_sleep(t_philo *philo)
{
	philo_print_message_if_alive("is eating", philo);
	philo->last_ate_us = gametime(philo->setup);
	sleep_while_not_dead(philo->setup->time_to_eat_ms * 1000, philo);
	unreserve_fork(philo, philo->right_fork);
	unreserve_fork(philo, philo->left_fork);
	if (check_for_death(philo) == DEAD)
		return (DEAD);
	philo_print_message_if_alive("is sleeping", philo);
	sleep_while_not_dead(philo->setup->time_to_sleep_ms * 1000, philo);
	return (ALIVE);
}

// How to solve problem 'philos dont die while thinking':
// Either move the bottom half of the below code to monitoring thread in a loop
// for each philosopher, or use a "try-lock" by building an array of fork states
// (protected by a mutex), and only lock if the array allows it.
static int	check_for_death(t_philo const *philo)
{
	int	time_since_last_meal_us;

	pthread_mutex_lock(philo->setup->status_mtx);
	if (philo->setup->status == DEAD)
	{
		pthread_mutex_unlock(philo->setup->status_mtx);
		return (DEAD);
	}
	time_since_last_meal_us = gametime(philo->setup) - philo->last_ate_us;
	if (time_since_last_meal_us > philo->setup->time_to_die_ms * 1000)
	{
		printf("%d %d died\n", gametime_ms(philo->setup), philo->num + 1);
		philo->setup->status = DEAD;
		pthread_mutex_unlock(philo->setup->status_mtx);
		return (DEAD);
	}
	pthread_mutex_unlock(philo->setup->status_mtx);
	return (ALIVE);
}
