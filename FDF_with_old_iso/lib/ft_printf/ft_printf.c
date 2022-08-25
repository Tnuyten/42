/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:07:36 by tnuyten           #+#    #+#             */
/*   Updated: 2022/06/01 16:08:03 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		written;

	written = 0;
	va_start(args, str);
	while (*str)
	{
		while (*str != '%' && *str != '\0')
			written += write(1, str++, 1);
		if (*str == '\0')
			break ;
		written += ft_do_format(*++str, args);
		str++;
	}
	va_end(args);
	return (written);
}

int	ft_do_format(char c, va_list args)
{
	size_t	written;

	if (c == '\0')
		return (0);
	written = 0;
	if (c == 'c')
		written += ft_do_c(args);
	else if (c == 's')
		written += ft_do_s(args);
	else if (c == 'p')
		written += ft_do_p(args);
	else if (c == 'd' || c == 'i')
		written += ft_do_di(args);
	else if (c == 'u')
		written += ft_do_u(args);
	else if (c == 'x')
		written += ft_do_x(args, 0);
	else if (c == 'X')
		written += ft_do_x(args, 1);
	else if (c == '%')
		written += write(1, "%", 1);
	return (written);
}
