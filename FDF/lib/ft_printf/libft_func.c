#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putnbr_fd(int n, int fd)
{
	int	written;

	written = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		written += write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		written += ft_putnbr_fd(n / 10, fd);
		written += ft_putnbr_fd(n % 10, fd);
	}
	else
		written += ft_putchar_fd(n + '0', fd);
	return (written);
}

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	int	written;

	written = 0;
	if (n >= 10)
	{
		written += ft_putnbr_u_fd(n / 10, fd);
		written += ft_putnbr_u_fd(n % 10, fd);
	}
	else
		written += ft_putchar_fd(n + '0', fd);
	return (written);
}

size_t	ft_strlen(const char *c)
{
	int	count;

	count = 0;
	while (*c++)
		count++;
	return (count);
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	return (write(fd, s, len));
}
