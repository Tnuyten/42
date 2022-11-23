/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:39:13 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/15 16:51:27 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_setup	t_setup;
typedef struct s_philo	t_philo;
typedef pthread_mutex_t	t_mutex;

# define ALIVE 0
# define DEAD 1

struct s_setup
{
	int		n_philos;
	int		time_to_die_ms;
	int		time_to_eat_ms;
	int		time_to_sleep_ms;
	int		courses;
	long	start_time;
	long	start_utime;
	t_mutex	*status_mtx;
	int		status;
};

struct s_philo
{
	int		num;
	t_mutex	*m_left_fork;
	t_mutex	*m_right_fork;
	int		last_ate_us;
	t_setup	*setup;
};

typedef struct timeval	t_time;
typedef struct timezone	t_zone;

// routine.c
void	*philosopher(void *arg);

// time.c
int		gettimediff(t_setup *setup);
int		gettimediff_ms(t_setup *setup);

// parse.c
void	parse(int argc, char **argv, t_setup *setup);

// t_philo.c
t_philo	*philo_new(int num, t_setup *setup, t_mutex *forks);
void	philo_add_forks(t_philo *philo, t_mutex *forks);
void	philo_free(t_philo *philo);
void	philo_print_message_if_alive(char *msg, t_philo *philo);

// ft_atoi.c
int		ft_atoi(const char *str);

// ft_calloc.c
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(int count, size_t size);

#endif