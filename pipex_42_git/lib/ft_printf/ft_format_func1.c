/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_func1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:26:09 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/15 18:52:26 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_itox(int fd, unsigned long n, int caser)
{
	char	*lower_symbols;
	char	*upper_symbols;
	int		written;

	lower_symbols = "0123456789abcdef";
	upper_symbols = "0123456789ABCDEF";
	written = 0;
	if (n > 15)
	{
		written += write_itox(fd, n / 16, caser);
		written += write_itox(fd, n % 16, caser);
	}
	else
	{
		if (caser == 1)
			written += write(fd, &upper_symbols[n], 1);
		else
			written += write(fd, &lower_symbols[n], 1);
	}
	return (written);
}

int	ft_do_c(int fd, va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write(fd, &c, 1));
}

int	ft_do_s(int fd, va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (s == NULL)
		return (ft_pf_putstr_fd("(null)", fd));
	return (ft_pf_putstr_fd(s, fd));
}

int	ft_do_p(int fd, va_list args)
{
	unsigned long	p;

	p = va_arg(args, unsigned long);
	write(fd, "0x", 2);
	return (write_itox(fd, p, 0) + 2);
}
