/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:14:56 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/07 18:25:37 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think()
{

}

void	take_forks()
{

}

void	place_forks()
{

}

void	eat()
{

}

int gettimediff(t_setup setup)
{
	t_time	time;
	int		timediff;

	gettimeofday(&time, NULL);
	timediff = (time.tv_sec - setup.start_time) * 1e6\
	+ (time.tv_usec - setup.start_utime);
	return (timediff);
}

void	*philosopher(void *arg)
{
	t_setup	setup;

	setup = *(t_setup *)arg;
	int i = 0;
	while (i++ < setup.philo_num * 10)
	{
		printf("%d: %07d us\n", setup.philo_num,  gettimediff(setup));
		usleep(1e5);
		think();
		take_forks();
		eat();
		place_forks();
	}
	return (NULL);
}