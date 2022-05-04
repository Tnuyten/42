/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations_reverse_rotate.h                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:19:46 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/04 12:43:00 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_OPERATIONS_REVERSE_ROTATE_H
# define QUEUE_OPERATIONS_REVERSE_ROTATE_H

# include "queue.h"
# include "queue_get.h"

void	rra(t_queue **a);
void	rrb(t_queue **b);
void	rrr(t_queue **a, t_queue **b);

#endif