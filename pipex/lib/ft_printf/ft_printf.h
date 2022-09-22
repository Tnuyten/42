/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:57:17 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/15 18:51:07 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		write_itox(int fd, unsigned long n, int caser);
int		ft_do_format(int fd, char c, va_list args);
int		ft_printf(const char *str, ...);
int		ft_dprintf(int fd, const char *str, ...);

int		ft_do_c(int fd, va_list args);
int		ft_do_s(int fd, va_list args);
int		ft_do_p(int fd, va_list args);
int		ft_do_di(int fd, va_list args);
int		ft_do_u(int fd, va_list args);
int		ft_do_x(int fd, va_list args, int caser);

int		ft_pf_putchar_fd(char c, int fd);
int		ft_pf_putnbr_fd(int n, int fd);
size_t	ft_pf_strlen(const char *c);
int		ft_pf_putstr_fd(char *s, int fd);
int		ft_pf_putnbr_u_fd(unsigned int n, int fd);

#endif
