/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:09:33 by tnuyten           #+#    #+#             */
/*   Updated: 2022/06/13 19:22:37 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue_operations_swap.h"

void	sa(t_queue **a)
{
	t_queue	*first;
	t_queue	*second;
	t_queue	*third;

	if (a[0] == NULL)
		return ;
	first = a[0];
	if (queue_size(first) < 2)
		return ;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	a[0] = second;
}

void	sb(t_queue **b)
{
	sa(b);
}

void	ss(t_queue **a, t_queue **b)
{
	sa(a);
	sb(b);
}
