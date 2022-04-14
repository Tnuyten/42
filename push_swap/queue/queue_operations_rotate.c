/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:18:13 by tnuyten           #+#    #+#             */
/*   Updated: 2022/04/14 15:34:19 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue_operations_rotate.h"

void	ra(t_queue **a)
{
	t_queue	*a_top;
	t_queue	*iter;

	a_top = a[0];
	iter = a[0];
	a[0] = a[0]->next;
	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	iter->next = a_top;
	a_top->next = NULL;
}

void	rb(t_queue **b)
{
	ra(b);
}

void	rr(t_queue **a, t_queue **b)
{
	ra(a);
	rb(b);
}
