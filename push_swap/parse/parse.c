/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:04:05 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/23 17:52:56 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// int sign: 1 for negative, 0 for positive.
// The number given is always positive.
int	str_is_int(char *str, int sign)
{
	long 		num;
	long		exp;
	int			i;
	int			j;

	num = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		exp = 1;
		j = 0;
		if (!ft_isdigit(str[i]))
			return (0);
		while (j < (int)ft_strlen(str) - i - 1)
		{
			exp *= 10;
			j++;
		}
		num += (str[i] - '0') * exp;
		if(num - sign > INT_MAX)
			return (0);
		i--;
	}
	return (1);
}

int	parse_input(t_queue **a, int argc, char **argv)
{
	int		number;
	char	*input;

	while (argc > 1)
	{
		input = argv[argc-- - 1];
		if (input[0] == '-')
		{
			if (!str_is_int(input + 1, 1))
				return (1);
		}
		else
		{
			if (!str_is_int(input, 0))
				return (1);
		}
		number = ft_atoi(input);
		queue_addfront(a, queue_new(number));
	}
	return (0);
}

int	has_duplicates(t_queue *queue)
{
	t_queue	*tmp;

	while (queue != NULL)
	{
		tmp = queue->next;
		while (tmp != NULL)
		{
			if (tmp->number == queue->number)
			{
				return (1);
			}
			tmp = tmp->next;
		}
		queue = queue->next;
	}
	return (0);
}
