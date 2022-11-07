/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:39:13 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/07 18:28:55 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_setup
{
	int		philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals;
	long	start_time;
	long	start_utime;
}		t_setup;

typedef struct s_philo
{
	int		num;
	t_setup	*setup;

}		t_philo;

typedef struct timeval	t_time;
typedef struct timezone	t_zone;

int		ft_atoi(const char *str);
void	*philosopher(void *arg);

#endif