#include "../inc/philo.h"

// A new philosopher sits at the table.
t_philo	*philo_new(int num, t_setup *setup, t_mutex *forks)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
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

void	philo_print_message_if_alive(char *msg, t_philo *philo)
{
	pthread_mutex_lock(philo->setup->status_mtx);
	if (philo->setup->status == ALIVE)
		printf("%d %d %s\n", (int)(gettimediff_ms(philo->setup)), \
		philo->num + 1, msg);
	pthread_mutex_unlock(philo->setup->status_mtx);
}
