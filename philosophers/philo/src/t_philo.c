/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibauld <thibauld@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:54:34 by thibauld          #+#    #+#             */
/*   Updated: 2022/11/29 17:42:39 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// A new philosopher sits at the table.
t_philo	*philo_new(int num, t_setup *setup)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	if (philo == NULL)
		return (NULL);
	philo->num = num;
	philo->setup = setup;
	philo->last_ate_us = 0;
	if (philo_add_forks(philo, setup->forks) == 0)
	{
		free(philo);
		return (NULL);
	}
	return (philo);
}

int	philo_add_forks(t_philo *philo, t_mutex *forks)
{
	int		f2;
	t_fork	*left_fork;
	t_fork	*right_fork;

	left_fork = ft_calloc(sizeof(t_fork), 1);
	right_fork = ft_calloc(sizeof(t_fork), 1);
	if (left_fork == NULL)
		return (0);
	if (right_fork == NULL)
	{
		free(left_fork);
		return (0);
	}
	if (philo->num + 1 == philo->setup->n_philos)
		f2 = 0;
	else
		f2 = philo->num + 1;
	left_fork->mutex = forks + philo->num;
	right_fork->mutex = forks + f2;
	left_fork->num = philo->num;
	right_fork->num = f2;
	philo->left_fork = left_fork;
	philo->right_fork = right_fork;
	return (1);
}

void	philo_free(t_philo *philo)
{
	pthread_mutex_destroy(philo->left_fork->mutex);
	free(philo->left_fork);
	free(philo->right_fork);
	free(philo);
}

void	philo_print_message_if_alive(char *msg, t_philo const *philo)
{
	pthread_mutex_lock(philo->setup->status_mtx);
	if (philo->setup->status == ALIVE)
		printf("%d %d %s\n", gametime_ms(philo->setup), philo->num + 1, msg);
	pthread_mutex_unlock(philo->setup->status_mtx);
}

// #include <string.h>
//
// static int	n_length(int n)
// {
// 	int	res;
//
// 	res = 0;
// 	if (n == 0)
// 		res++;
// 	if (n < 0)
// 	{
// 		n = -n;
// 		res++;
// 	}
// 	while (n > 0)
// 	{
// 		n /= 10;
// 		res++;
// 	}
// 	return (res);
// }
//
// char	*ft_itoa(int n)
// {
// 	int		i;
// 	char	*res;
//
// 	if (n == -2147483648)
// 	{
// 		return (strdup("-2147483648"));
// 	}
// 	i = n_length(n);
// 	res = malloc(i + 1);
// 	if (!res)
// 		return (NULL);
// 	res[i] = '\0';
// 	res[0] = '0';
// 	if (n < 0)
// 	{
// 		n = -n;
// 		res[0] = '-';
// 	}
// 	while (n > 0)
// 	{
// 		--i;
// 		res[i] = n % 10 + '0';
// 		n /= 10;
// 	}
// 	return (res);
// }
//
// char *strjoin(char *s1, char *s2)
// {
// 	char *res;
//
// 	res = malloc(strlen(s1) + strlen(s2) + 1);
// 	if (res)
// 	{
// 		strcpy(res, s1);
// 		strcat(res, s2);
// 	}
// 	return (res);
// }
//
// void	philo_print_message_if_alive(char *msg, t_philo const *philo)
// {
// 	char *reset = "\e[0m";
// 	char *color_prefix = "\e[0;";
// 	char *color_suffix = "m";
// 	char *num = ft_itoa(philo->num + 90);
// 	char *color_t = strjoin(color_prefix, num);
// 	char *color = strjoin(color_t, color_suffix);
//
// 	pthread_mutex_lock(philo->setup->status_mtx);
// 	if (philo->setup->status == ALIVE)
// 		printf("%s%s%d %d %s%s\n", reset, color,
// 			gametime_ms(philo->setup), philo->num + 1, msg, reset);
// 	else
// 		printf("Dead: %d %d %s\n", gametime_ms(philo->setup),
// 			philo->num + 1, msg);
// 	pthread_mutex_unlock(philo->setup->status_mtx);
// 	free(color_t);
// 	free(color);
// 	free(num);
// }
