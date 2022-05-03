/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:57:17 by tnuyten           #+#    #+#             */
/*   Updated: 2022/04/15 20:13:07 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		write_itox(unsigned long n, int caser);
int		ft_do_format(char c, va_list args);
int		ft_printf(const char *str, ...);

int		ft_do_c(va_list args);
int		ft_do_s(va_list args);
int		ft_do_p(va_list args);
int		ft_do_di(va_list args);
int		ft_do_u(va_list args);
int		ft_do_x(va_list args, int caser);

int		ft_printf_putchar_fd(char c, int fd);
int		ft_printf_putnbr_fd(int n, int fd);
size_t	ft_printf_strlen(const char *c);
int		ft_printf_putstr_fd(char *s, int fd);
int		ft_printf_putnbr_u_fd(unsigned int n, int fd);

#endif
