/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations_reverse_rotate.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:19:33 by tnuyten           #+#    #+#             */
/*   Updated: 2022/04/14 15:34:16 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue_operations_reverse_rotate.h"

void	rra(t_queue **a)
{
	t_queue	*iter;
	t_queue	*penultimate;
	t_queue	*a_top;
	size_t	siz;

	siz = queue_size(a[0]);
	if (siz <= 1)
		return ;
	iter = a[0];
	while (iter->next != NULL)
	{
		if (iter->next->next == NULL)
		{
			penultimate = iter;
		}
		iter = iter->next;
	}
	a_top = a[0];
	penultimate->next = NULL;
	a[0] = iter;
	iter->next = a_top;
}

void	rrb(t_queue **b)
{
	rra(b);
}

void	rrr(t_queue **a, t_queue **b)
{
	rra(a);
	rrb(b);
}
