/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:15:04 by tnuyten           #+#    #+#             */
/*   Updated: 2022/06/13 19:35:54 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue_operations_push.h"
#include "../ft_printf/ft_printf.h"

void	pa(t_queue **a, t_queue **b)
{
	t_queue	*a_top;
	t_queue	*b_top;

	if (b[0] == NULL)
		return ;
	a_top = a[0];
	b_top = b[0];
	b[0] = b[0]->next;
	a[0] = b_top;
	a[0]->next = a_top;
}

void	pb(t_queue **a, t_queue **b)
{
	pa(b, a);
}
