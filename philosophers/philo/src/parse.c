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
