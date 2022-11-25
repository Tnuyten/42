/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibauld <thibauld@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:24:37 by thibauld          #+#    #+#             */
/*   Updated: 2022/11/26 00:16:16 by thibauld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	gettimediff(t_setup *setup)
{
	t_time	time;
	int		timediff;

	gettimeofday(&time, NULL);
	timediff = (time.tv_sec - setup->start_time) * 1e6 + \
	(time.tv_usec - setup->start_utime);
	return (timediff);
}

int	gettimediff_ms(t_setup *setup)
{
	return (gettimediff(setup) * 0.001);
}

void	stupid_sleep(t_setup *setup, int us)
{
	int		now;
	int		then;

	now = gettimediff(setup);
	usleep(us);
	then = gettimediff(setup);
	while (now + us > then)
		usleep(1);
}

void	sleep_while_not_dead(int sleep_time, t_philo *philo)
{
	int	start;
	int	now;
	int	time_since_last_meal;

	now = gettimediff(philo->setup);
	start = now;
	time_since_last_meal = gettimediff(philo->setup) - philo->last_ate_us;
	while (now - start < sleep_time)
	{
		time_since_last_meal = gettimediff(philo->setup) - philo->last_ate_us;
		if (time_since_last_meal > philo->setup->time_to_die_ms * 1000)
			break ;
		usleep(500);
		now = gettimediff(philo->setup);
	}
}
