/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:14:56 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/26 00:27:50 by thibauld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	take_forks(t_philo const *philo);
static int	eat_and_sleep(t_philo *philo);
static int	check_for_death(t_philo const *philo);

static int	routine(t_philo const *philo)
{
	if (check_for_death(philo) == DEAD)
		return (1);
	philo_print_message_if_alive("is thinking", philo);
	if (take_forks(philo) == DEAD)
		return (1);
	if (check_for_death(philo) == DEAD)
	{
		pthread_mutex_unlock(philo->m_left_fork);
		pthread_mutex_unlock(philo->m_right_fork);
		return (1);
	}
	if (eat_and_sleep((t_philo *)philo) == DEAD)
		return (1);
	if (check_for_death(philo) == DEAD)
		return (1);
	return (0);
}

void	*philosopher(void *arg)
{
	t_philo const	*philo = (t_philo const *)arg;
	int				i;
	int				courses;

	if (philo->num % 2 == 1)
		usleep(500);
	courses = philo->setup->courses;
	i = 0;
	while (1)
	{
		if (courses != -1 && i++ >= courses)
			break ;
		if (routine(philo) == 1)
			break ;
	}
	return (NULL);
}

// Philosophers pick up forks in a set order to avoid lock cycles.
// The philosophers think until they can pick up both forks i.e. the threads are
// suspended until they can do so.
static int	take_forks(t_philo const *philo)
{
	t_mutex	*f1;
	t_mutex	*f2;
	int		sleepytime;

	f1 = philo->m_left_fork;
	f2 = philo->m_right_fork;
	if (philo->num % 2 == 0)
		swap_forks(&f1, &f2);
	// if (philo->setup->n_philos % 2 == 1)
	// {
	// 	sleepytime = philo->setup->time_to_eat_ms * 2 - philo->setup->time_to_sleep_ms;
	// 	printf("%d\n", sleepytime);
	// 	if (sleepytime > 0)
	// 		sleep_while_not_dead(sleepytime, (t_philo*)philo);
	// }
	pthread_mutex_lock(f1);
	if (check_for_death(philo) == DEAD)
	{
		pthread_mutex_unlock(f1);
		return (DEAD);
	}
	philo_print_message_if_alive("has taken a fork", philo);
	pthread_mutex_lock(f2);
	if (check_for_death(philo) == DEAD)
	{
		pthread_mutex_unlock(f1);
		pthread_mutex_unlock(f2);
		return (DEAD);
	}
	philo_print_message_if_alive("has taken a fork", philo);
	return (ALIVE);
}

static int	eat_and_sleep(t_philo *philo)
{
	t_mutex	*f1;
	t_mutex	*f2;

	philo_print_message_if_alive("is eating", philo);
	philo->last_ate_us = gettimediff(philo->setup);
	sleep_while_not_dead(philo->setup->time_to_eat_ms * 1000, philo);
	// usleep(philo->setup->time_to_eat_ms * 1000);
	f1 = philo->m_right_fork;
	f2 = philo->m_left_fork;
	pthread_mutex_unlock(f1);
	pthread_mutex_unlock(f2);
	if (check_for_death(philo) == DEAD)
		return (DEAD);
	philo_print_message_if_alive("is sleeping", philo);
	sleep_while_not_dead(philo->setup->time_to_sleep_ms * 1000, philo);
	// usleep(philo->setup->time_to_sleep_ms * 1000);
	return (ALIVE);
}

static int	check_for_death(t_philo const *philo)
{
	int	time_since_last_meal_us;

	pthread_mutex_lock(philo->setup->status_mtx);
	if (philo->setup->status == DEAD)
	{
		pthread_mutex_unlock(philo->setup->status_mtx);
		return (DEAD);
	}
	time_since_last_meal_us = gettimediff(philo->setup) - philo->last_ate_us;
	if (time_since_last_meal_us > philo->setup->time_to_die_ms * 1000)
	{
		printf("%d %d died\n", gettimediff_ms(philo->setup), philo->num + 1);
		philo->setup->status = DEAD;
		pthread_mutex_unlock(philo->setup->status_mtx);
		return (DEAD);
	}
	pthread_mutex_unlock(philo->setup->status_mtx);
	return (ALIVE);
}
