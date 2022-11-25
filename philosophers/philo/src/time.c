#include "../inc/philo.h"

int	gettimediff(t_setup *setup)
{
	t_time	time;
	int		timediff;

	gettimeofday(&time, NULL);
	timediff = (time.tv_sec - setup->start_time) * 1e6 + \
	(time.tv_usec - setup->start_utime);
	return (timediff);
}

int	gettimediff_ms(t_setup *setup)
{
	return (gettimediff(setup) * 0.001);
}

<<<<<<< HEAD
// void stupid_sleep(t_setup *setup, int us)
// {
// 	int		now;
// 	int		then;
//
// 	now = gettimediff(setup);
// 	usleep(us);
// 	then = gettimediff(setup);
//
// 	while (now + us > then)
// 		usleep(1);
// }
=======
void stupid_sleep(t_setup *setup, int us)
{
	int		now;
	int		then;

	now = gettimediff(setup);
	usleep(us);
	then = gettimediff(setup);

	while (now + us > then)
		usleep(1);
}
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
