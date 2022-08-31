/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:13:08 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/23 17:47:41 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	queue_print(t_queue *queue)
{
	while (queue)
	{
		ft_printf("[%d]->", queue->number);
		queue = queue->next;
	}
	ft_printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_queue	*a;
	t_queue	*b;

	b = NULL;
	if (argc < 2)
		return (1);
	if (parse_input(&a, argc, argv))
	{
		ft_printf("%s\n", "Error");
		queue_clear(&a);
		return (1);
	}
	if (has_duplicates(a))
	{
		ft_printf("%s\n", "Error");
		queue_clear(&a);
		return (1);
	}
	sort(&a, &b);
	queue_clear(&a);
	queue_clear(&b);
	return (0);
}
