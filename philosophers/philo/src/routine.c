/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:14:56 by tnuyten           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/24 23:37:19 by tnuyten          ###   ########.fr       */
=======
/*   Updated: 2022/11/15 19:55:49 by tnuyten          ###   ########.fr       */
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

<<<<<<< HEAD
static int	take_forks(t_philo const *philo);
static int	eat_and_sleep(t_philo *philo);
static int	check_for_death(t_philo const *philo);

void	*philosopher(void *arg)
{
	t_philo const	*philo = (t_philo const *)arg;
	int				i;
	int				courses;

=======
static int	take_forks(t_philo *philo);
static int	eat_and_sleep(t_philo *philo);
static int	is_dead(t_philo *philo);

void	*philosopher(void *arg)
{
	t_philo	*philo;
	int		i;
	int		courses;

	philo = (t_philo *)arg;
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
	courses = philo->setup->courses;
	i = 0;
	while (1)
	{
		if (courses != -1 && i++ >= courses)
			break ;
<<<<<<< HEAD
		if (check_for_death(philo) == DEAD)
=======
		if (is_dead(philo) == DEAD)
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
			break ;
		philo_print_message_if_alive("is thinking", philo);
		if (take_forks(philo) == DEAD)
			break ;
<<<<<<< HEAD
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
=======
		if (eat_and_sleep(philo) == DEAD)
			break ;
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
	}
	return (NULL);
}

// Philosophers pick up forks in a set order to avoid lock cycles.
// The philosophers think until they can pick up both forks i.e. the threads are
// suspended until they can do so.
<<<<<<< HEAD
static int	take_forks(t_philo const *philo)
=======
static int	take_forks(t_philo *philo)
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
{
	t_mutex	*f1;
	t_mutex	*f2;

<<<<<<< HEAD
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
=======
	if (philo->num % 2 == 0)
	{
		(void)f1;
	}
	else
	{
		usleep(philo->setup->time_to_eat_ms * 2 \
			- philo->setup->time_to_sleep_ms);
	}
	if (philo->num % 2 == 0)
	{
		f1 = philo->m_right_fork;
		f2 = philo->m_left_fork;
	}
	else
	{
		f1 = philo->m_left_fork;
		f2 = philo->m_right_fork;
	}
	pthread_mutex_lock(f1);
	philo_print_message_if_alive("has taken a fork", philo);
	pthread_mutex_lock(f2);
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
	philo_print_message_if_alive("has taken a fork", philo);
	return (ALIVE);
}

static int	eat_and_sleep(t_philo *philo)
{
	t_mutex	*f1;
	t_mutex	*f2;

<<<<<<< HEAD
	philo_print_message_if_alive("is eating", philo);
=======
	// philo_print_message_if_alive("\033[0;31mis eating\033[0m", philo);
	philo_print_message_if_alive("is eating", philo);

>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
	philo->last_ate_us = gettimediff(philo->setup);
	usleep(philo->setup->time_to_eat_ms * 1000);
	f1 = philo->m_right_fork;
	f2 = philo->m_left_fork;
	pthread_mutex_unlock(f1);
<<<<<<< HEAD
	// philo_print_message_if_alive("has dropped a fork 1", philo);
	pthread_mutex_unlock(f2);
	// philo_print_message_if_alive("has dropped a fork 2", philo);
	// if (check_for_death(philo) == DEAD)
	// 	return (DEAD);
=======
	pthread_mutex_unlock(f2);
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
	philo_print_message_if_alive("is sleeping", philo);
	usleep(philo->setup->time_to_sleep_ms * 1000);
	return (ALIVE);
}

<<<<<<< HEAD
static int	check_for_death(t_philo const *philo)
=======
static int	is_dead(t_philo *philo)
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
{
	int	time_since_last_meal_us;

	pthread_mutex_lock(philo->setup->status_mtx);
	if (philo->setup->status == DEAD)
	{
		pthread_mutex_unlock(philo->setup->status_mtx);
		return (DEAD);
	}
<<<<<<< HEAD

	time_since_last_meal_us = gettimediff(philo->setup) - philo->last_ate_us;
	if (time_since_last_meal_us > philo->setup->time_to_die_ms * 1000)
	{
		// printf("%d %d died\n", gettimediff_ms(philo->setup), philo->num + 1);
		philo->setup->status = DEAD;
		pthread_mutex_unlock(philo->setup->status_mtx);
		return (DEAD);
	}
	pthread_mutex_unlock(philo->setup->status_mtx);
=======
	pthread_mutex_unlock(philo->setup->status_mtx);
	time_since_last_meal_us = gettimediff(philo->setup) - philo->last_ate_us;
	if (time_since_last_meal_us > philo->setup->time_to_die_ms * 1000)
	{
		pthread_mutex_lock(philo->setup->status_mtx);
		philo->setup->status = DEAD;
		printf("%d %d died.\n", gettimediff_ms(philo->setup), philo->num + 1);
		pthread_mutex_unlock(philo->setup->status_mtx);
		return (DEAD);
	}
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
	return (ALIVE);
}
