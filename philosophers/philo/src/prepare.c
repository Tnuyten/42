#include "../inc/philo.h"

void	parse(int argc, char **argv, t_setup *setup)
{
	t_time	time;

	setup->n_philos = ft_atoi(argv[1]);
	setup->time_to_die_ms = ft_atoi(argv[2]);
	setup->time_to_eat_ms = ft_atoi(argv[3]);
	setup->time_to_sleep_ms = ft_atoi(argv[4]);
	if (argc == 6)
		setup->courses = ft_atoi(argv[5]);
	else
		setup->courses = -1;
	gettimeofday(&time, NULL);
	setup->start_time = time.tv_sec;
	setup->start_utime = time.tv_usec;
	setup->status = ALIVE;
}

int	prepare(t_setup *setup, t_mutex **forks, t_philo ***philos)
{
	int	i;

	// printf("Forks: 0x%X\n", forks);
	// for(int i = 0; i < setup.n_philos; i++)
	// 	printf("Fork[%d]: 0x%X\n", i, &forks[i]);
	//
	// printf("Philos: 0x%X\n", philos);
	// for(int i = 0; i < setup.n_philos; i++)
	// 	printf("Philo[%d]: 0x%X\n", i, &philos[i]);

	setup->status_mtx = ft_calloc(sizeof(t_mutex), 1);
	if (setup->status_mtx == NULL)
		return (1);
	if (pthread_mutex_init(setup->status_mtx, NULL) == 1)
		return (1);
	// printf("status_mtx: %p   -   %p\n", &setup->status_mtx, setup->status_mtx);
	i = -1;
	// printf("Forks: 0x%X\n", *forks);
	while (++i < setup->n_philos)
	{
		if (pthread_mutex_init(&(*forks)[i], NULL) == 1)
			return (1);
		// printf("Fork[%d]: 0x%X   -   0x%X\n", i, &(*forks)[i], (*forks)[i]);
	}
	i = -1;
	// printf("Philos: 0x%X\n", philos);
	while (++i < setup->n_philos)
	{
		(*philos)[i] = philo_new(i, setup, *forks);
		if ((*philos)[i] == NULL)
			return (1);
		// printf("Philo[%d]: 0x%X   -   0x%X\n", i, &(*philos)[i], (*philos)[i]);
	}
	return (0);
}

void	swap_forks(t_mutex **f1, t_mutex **f2)
{
	t_mutex	*temp;

	temp = *f1;
	*f1 = *f2;
	*f2 = temp;
}
