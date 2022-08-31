/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:54 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/27 15:42:35 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct s_queue
{
	int				number;
	struct s_queue	*next;
}	t_queue;

t_queue	*queue_new(int num);
void	queue_addback(t_queue **queue, t_queue *new_queue);
void	queue_addfront(t_queue **queue, t_queue *new_queue);
void	queue_delone(t_queue *queue);
void	queue_clear(t_queue **queue);

#endif