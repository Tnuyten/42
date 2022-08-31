/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_get.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:28:02 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/09 15:31:35 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_GET_H
# define QUEUE_GET_H

# include "queue.h"

int		queue_index(t_queue **root, t_queue *target);
t_queue	*queue_get_node(t_queue **root, int num);
t_queue	*queue_copy(t_queue *root);
t_queue	*queue_last(t_queue *queue);
int		queue_size(t_queue *queue);

#endif