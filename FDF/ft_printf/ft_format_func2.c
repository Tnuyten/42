#include "ft_printf.h"

int	ft_do_di(va_list args)
{
	signed int	d;

	d = va_arg(args, signed int);
	return (ft_putnbr_fd(d, 1));
}

int	ft_do_u(va_list args)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	return (ft_putnbr_u_fd(u, 1));
}

int	ft_do_x(va_list args, int caser)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	return (write_itox(x, caser));
}
