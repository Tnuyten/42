/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibauld <thibauld@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:54:34 by thibauld          #+#    #+#             */
/*   Updated: 2022/11/25 22:54:36 by thibauld         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// A new philosopher sits at the table.
t_philo	*philo_new(int num, t_setup *setup, t_mutex *forks)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	if (philo == NULL)
		return (NULL);
	philo->num = num;
	philo->setup = setup;
	philo->last_ate_us = 0;
	philo_add_forks(philo, forks);
	return (philo);
}

void	philo_add_forks(t_philo *philo, t_mutex *forks)
{
	int	f2;

	if (philo->num + 1 == philo->setup->n_philos)
		f2 = 0;
	else
		f2 = philo->num + 1;
	philo->m_left_fork = forks + philo->num;
	philo->m_right_fork = forks + f2;
}

void	philo_free(t_philo *philo)
{
	pthread_mutex_destroy(philo->m_left_fork);
	free(philo);
}

void	philo_print_message_if_alive(char *msg, t_philo const *philo)
{
	pthread_mutex_lock(philo->setup->status_mtx);
	if (philo->setup->status == ALIVE)
		printf("%d %d %s\n", gettimediff_ms(philo->setup), philo->num + 1, msg);
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
// 			gettimediff_ms(philo->setup), philo->num + 1, msg, reset);
// 	else
// 		printf("Dead: %d %d %s\n", gettimediff_ms(philo->setup),
// 			philo->num + 1, msg);
// 	pthread_mutex_unlock(philo->setup->status_mtx);
// 	free(color_t);
// 	free(color);
// 	free(num);
// }
