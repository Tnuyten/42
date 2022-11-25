/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:14:56 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/24 23:37:19 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	take_forks(t_philo const *philo);
static int	eat_and_sleep(t_philo *philo);
static int	check_for_death(t_philo const *philo);

void	*philosopher(void *arg)
{
	t_philo const	*philo = (t_philo const *)arg;
	int				i;
	int				courses;

	courses = philo->setup->courses;
	i = 0;
	while (1)
	{
		if (courses != -1 && i++ >= courses)
			break ;
		if (check_for_death(philo) == DEAD)
			break ;
		philo_print_message_if_alive("is thinking", philo);
		if (take_forks(philo) == DEAD)
			break ;
		// if (check_for_death(philo) == DEAD)
		// {
		// 	pthread_mutex_unlock(philo->m_left_fork);
		// 	pthread_mutex_unlock(philo->m_right_fork);
		// 	break ;
		// }
		if (eat_and_sleep((t_philo *)philo) == DEAD)
			break ;
		// if (check_for_death(philo) == DEAD)
		// 	break ;
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

	f1 = philo->m_left_fork;
	f2 = philo->m_right_fork;
	if (philo->num % 2 == 0)
		swap_forks(&f1, &f2);
	pthread_mutex_lock(f1);
	// if (check_for_death(philo) == DEAD)
	// {
	// 	pthread_mutex_unlock(f1);
	// 	return (DEAD);
	// }
	philo_print_message_if_alive("has taken a fork", philo);
	pthread_mutex_lock(f2);
	// if (check_for_death(philo) == DEAD)
	// {
	// 	pthread_mutex_unlock(f1);
	// 	pthread_mutex_unlock(f2);
	// 	return (DEAD);
	// }
	philo_print_message_if_alive("has taken a fork", philo);
	return (ALIVE);
}

static int	eat_and_sleep(t_philo *philo)
{
	t_mutex	*f1;
	t_mutex	*f2;

	philo_print_message_if_alive("is eating", philo);
	philo->last_ate_us = gettimediff(philo->setup);
	usleep(philo->setup->time_to_eat_ms * 1000);
	f1 = philo->m_right_fork;
	f2 = philo->m_left_fork;
	pthread_mutex_unlock(f1);
	// philo_print_message_if_alive("has dropped a fork 1", philo);
	pthread_mutex_unlock(f2);
	// philo_print_message_if_alive("has dropped a fork 2", philo);
	// if (check_for_death(philo) == DEAD)
	// 	return (DEAD);
	philo_print_message_if_alive("is sleeping", philo);
	usleep(philo->setup->time_to_sleep_ms * 1000);
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
		// printf("%d %d died\n", gettimediff_ms(philo->setup), philo->num + 1);
		philo->setup->status = DEAD;
		pthread_mutex_unlock(philo->setup->status_mtx);
		return (DEAD);
	}
	pthread_mutex_unlock(philo->setup->status_mtx);
	return (ALIVE);
}
