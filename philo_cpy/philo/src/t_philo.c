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
	// printf("%d ", philo->setup->status);
	if (philo->setup->status == ALIVE)
		printf("%d %d %s\n", gettimediff_ms(philo->setup), philo->num + 1, msg);
	/* else
	// 	printf("Dead: %d %d %s\n", gettimediff_ms(philo->setup), \
	// 		philo->num + 1, msg);
	*/
	pthread_mutex_unlock(philo->setup->status_mtx);
}

// #include <string.h>
//
// char* itoa(int val, int base){
//
// 	char *buf = malloc(300);
//
// 	int i = 30;
//
// 	ft_bzero(buf, 32);
// 	for(; val && i ; --i, val /= base)
//
// 		buf[i] = "0123456789abcdef"[val % base];
//
// 	return (&buf[i+1]);
//
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
/* void	philo_print_message_if_alive(char *msg, t_philo const *philo)
// {
// 	char *reset = "\e[0m";
// 	char *color_prefix = "\e[0;";
// 	char *color_suffix = "m";
// 	char *num = itoa(philo->num + 90, 10);
// 	char *color_t = strjoin(color_prefix, num);
// 	char *color = strjoin(color_t, color_suffix);
//
// 	pthread_mutex_lock(philo->setup->status_mtx);
// 	printf("%d ", philo->setup->status);
// 	if (philo->setup->status == ALIVE)
// 		printf("%s%s%d %d %s%s\n", reset, color, \
// 			gettimediff_ms(philo->setup), philo->num + 1, msg, reset);
// 	else
// 		printf("Dead: %d %d %s\n", gettimediff_ms(philo->setup), \
// 			philo->num + 1, msg);
// 	pthread_mutex_unlock(philo->setup->status_mtx);
// 	free(color_t);
// 	free(color);
// 	free(num);
// }
*/
