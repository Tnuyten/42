/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:39:13 by tnuyten           #+#    #+#             */
/*   Updated: 2022/11/29 17:48:32 by tnuyten          ###   ########.fr       */
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
typedef struct s_fork	t_fork;
typedef struct timeval	t_time;
typedef struct timezone	t_zone;

# define ALIVE 0
# define DEAD 1

struct s_setup
{
	int			n_philos;
	int			time_to_die_ms;
	int			time_to_eat_ms;
	int			time_to_sleep_ms;
	int			courses;

	pthread_t	*threads;
	t_mutex		*forks;
	t_philo		**philos;
	long		start_time;
	long		start_utime;

	int			status;
	t_mutex		*status_mtx;

	int			*fork_states;
	t_mutex		*fork_states_mtx;
};

struct s_fork
{
	t_mutex	*mutex;
	int		num;
};

struct s_philo
{
	int		num;
	t_fork	*left_fork;
	t_fork	*right_fork;
	int		last_ate_us;
	t_setup	*setup;
};

// routine.c
void	*philosopher(void *arg);

// routine_util.c
int		try_reserve_fork(t_philo const *philo, t_fork *fork);
void	unreserve_fork(t_philo const *philo, t_fork *fork);

// time.c
int		gametime(t_setup *setup);
int		gametime_ms(t_setup *setup);
void	sleep_while_not_dead(int sleep_time, t_philo const *philo);

// prepare.c
int		parse(int argc, char **argv, t_setup *setup);
int		prepare(t_setup *setup);

// t_philo.c
t_philo	*philo_new(int num, t_setup *setup);
int		philo_add_forks(t_philo *philo, t_mutex *forks);
void	philo_free(t_philo *philo);
void	philo_print_message_if_alive(char *msg, t_philo const *philo);

// ft_atoi.c
int		ft_atoi(const char *str);

// ft_calloc.c
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(int count, size_t size);

// cleanup.c
void	cleanup(t_setup *setup);
void	finish(t_setup *setup);

#endif