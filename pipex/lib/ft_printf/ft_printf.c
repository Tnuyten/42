/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:07:36 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/15 19:04:40 by tnuyten          ###   ########.fr       */
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
		written += ft_do_format(1, *++str, args);
		str++;
	}
	va_end(args);
	return (written);
}

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		written;

	written = 0;
	va_start(args, str);
	while (*str)
	{
		while (*str != '%' && *str != '\0')
			written += write(fd, str++, 1);
		if (*str == '\0')
			break ;
		written += ft_do_format(fd, *++str, args);
		str++;
	}
	va_end(args);
	return (written);
}

int	ft_do_format(int fd, char c, va_list args)
{
	size_t	written;

	if (c == '\0')
		return (0);
	written = 0;
	if (c == 'c')
		written += ft_do_c(fd, args);
	else if (c == 's')
		written += ft_do_s(fd, args);
	else if (c == 'p')
		written += ft_do_p(fd, args);
	else if (c == 'd' || c == 'i')
		written += ft_do_di(fd, args);
	else if (c == 'u')
		written += ft_do_u(fd, args);
	else if (c == 'x')
		written += ft_do_x(fd, args, 0);
	else if (c == 'X')
		written += ft_do_x(fd, args, 1);
	else if (c == '%')
		written += write(fd, "%", 1);
	return (written);
}
