/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibauld <thibauld@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:24:37 by thibauld          #+#    #+#             */
/*   Updated: 2022/11/28 13:54:37 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	gametime(t_setup *setup)
{
	t_time	time;
	int		timediff;

	gettimeofday(&time, NULL);
	timediff = (time.tv_sec - setup->start_time) * 1e6 + \
	(time.tv_usec - setup->start_utime);
	return (timediff);
}

int	gametime_ms(t_setup *setup)
{
	return (gametime(setup) * 0.001);
}

void	sleep_while_not_dead(int sleep_time, t_philo const *philo)
{
	int	start;
	int	now;
	int	time_since_last_meal;

	start = gametime(philo->setup);
	now = start;
	while (now - start < sleep_time)
	{
		time_since_last_meal = now - philo->last_ate_us;
		if (time_since_last_meal > philo->setup->time_to_die_ms * 1000)
			break ;
		usleep(500);
		now = gametime(philo->setup);
	}
}
