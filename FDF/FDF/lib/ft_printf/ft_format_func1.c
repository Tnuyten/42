/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_func1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:26:09 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/30 21:26:10 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_itox(unsigned long n, int caser)
{
	char	*lower_symbols;
	char	*upper_symbols;
	int		written;

	lower_symbols = "0123456789abcdef";
	upper_symbols = "0123456789ABCDEF";
	written = 0;
	if (n > 15)
	{
		written += write_itox(n / 16, caser);
		written += write_itox(n % 16, caser);
	}
	else
	{
		if (caser == 1)
			written += write(1, &upper_symbols[n], 1);
		else
			written += write(1, &lower_symbols[n], 1);
	}
	return (written);
}

int	ft_do_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int	ft_do_s(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (s == NULL)
		return (ft_pf_putstr_fd("(null)", 1));
	return (ft_pf_putstr_fd(s, 1));
}

int	ft_do_p(va_list args)
{
	unsigned long	p;

	p = va_arg(args, unsigned long);
	write(1, "0x", 2);
	return (write_itox(p, 0) + 2);
}
