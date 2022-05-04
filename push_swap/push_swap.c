/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:13:08 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/04 12:26:06 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_queue	*a;
	t_queue	*b;

	b = NULL;
	if (argc < 2)
	{
		ft_printf("%s\n", "Error - No arguments provided.");
		return (1);
	}
	parse_input(&a, argc, argv);
	if (has_duplicates(a))
	{
		ft_printf("%s\n", "Error - Duplicate number found.");
		queue_clear(&a);
		return (1);
	}
	sort(&a, &b);
	queue_clear(&a);
	queue_clear(&b);
	return (0);
}

//#TODO improve.. this won't work for "1 2 3 4 5" ... but it doesn't have to?!
int	parse_input(t_queue **a, int argc, char **argv)
{
	int		number;

	*a = queue_new(ft_atoi(argv[argc-- - 1]));
	while (argc > 1)
	{
		number = ft_atoi(argv[argc-- - 1]);
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
