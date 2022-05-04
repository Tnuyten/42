/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_queue_helpers_more.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:12:44 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/04 12:28:07 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_QUEUE_HELPERS_MORE_H
# define SORT_QUEUE_HELPERS_MORE_H

# include "../queue/queue.h"
# include "../queue/queue_get.h"
# include "../queue/queue_operations_rotate.h"
# include "../queue/queue_operations_reverse_rotate.h"
# include "../ft_printf/ft_printf.h"

int		find_insert_location(t_queue **a, t_queue *target);
void	rotate_efficiently(t_queue **a, int index);
int		get_largest_node_lower_than_target(t_queue **a, t_queue *target);

#endif