/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:01:55 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/18 20:38:26 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
	{
		return (1);
	}
	return (0);
}

//function edited (cap res at 255) for parse_line's parse_color.
uint32_t	ft_atoi(const char *nptr)
{
	int			sign;
	uint32_t	res;

	sign = 1;
	res = 0;
	while (ft_isspace(*nptr))
	{
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
		{
			sign *= -1;
		}
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr != '\0')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (sign * res);
}
