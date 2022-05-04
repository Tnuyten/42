/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_queue.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:44:05 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/04 12:41:18 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_QUEUE_H
# define SORT_QUEUE_H

# include "sort_queue_helpers.h"
# include "../queue/queue.h"
# include "../queue/queue_get.h"
# include "../queue/queue_operations_push.h"
# include "../queue/queue_operations_swap.h"
# include "../queue/queue_operations_rotate.h"
# include "../queue/queue_operations_reverse_rotate.h"
# include "../ft_printf/ft_printf.h"
# include "../sort/sort_queue_helpers_more.h"

void	sort(t_queue **a, t_queue **b);
void	radix_sort(t_queue **a, t_queue **b);
void	sort_three(t_queue **a);
void	sort_small(t_queue **a, t_queue **b);
void	ra_or_pb(t_queue **a, t_queue **b, int mask);

#endif