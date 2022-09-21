/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:26:07 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/15 19:09:15 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_do_di(int fd, va_list args)
{
	signed int	d;

	d = va_arg(args, signed int);
	return (ft_pf_putnbr_fd(d, fd));
}

int	ft_do_u(int fd, va_list args)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	return (ft_pf_putnbr_u_fd(u, fd));
}

int	ft_do_x(int fd, va_list args, int caser)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	return (write_itox(fd, x, caser));
}
