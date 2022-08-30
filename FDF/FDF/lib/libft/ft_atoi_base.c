/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:01:55 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/30 17:29:05 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iscapital(int c)
{
	return (c >= 65 && c <= 90);
}

static int	ft_atoi_base_inner(const char *nptr)
{
	int	num;

	if (!ft_isdigit(*nptr))
	{
		if (ft_iscapital(*nptr) == 1)
		{
			num = *nptr - 'A' + 10;
		}
		else
		{
			num = *nptr - 'a' + 10;
		}
	}
	else
	{
		num = *nptr - '0';
	}
	return (num);
}

int	ft_atoi_base(const char *nptr, int base)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '0' && (*(nptr + 1) == 'x' || *(nptr + 1) == 'X'))
	{
		nptr += 2;
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isalnum(*nptr) && *nptr != '\0')
	{
		res = res * base + ft_atoi_base_inner(nptr);
		nptr++;
	}
	return (sign * res);
}
