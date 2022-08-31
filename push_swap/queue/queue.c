/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:35:44 by tnuyten           #+#    #+#             */
/*   Updated: 2022/07/07 16:55:19 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*queue_new(int num)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (queue == NULL)
		return (NULL);
	queue->number = num;
	queue->next = NULL;
	return (queue);
}

void	queue_addback(t_queue **root, t_queue *new_queue)
{
	t_queue	*tmp;

	if (!root)
		return ;
	if (root[0] == NULL)
	{
		root[0] = new_queue;
		return ;
	}
	tmp = root[0];
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_queue;
}

void	queue_addfront(t_queue **root, t_queue *new_queue)
{
	if (!root || !new_queue)
		return ;
	if (!root[0])
	{
		root[0] = new_queue;
		return ;
	}
	new_queue->next = root[0];
	root[0] = new_queue;
}

void	queue_delone(t_queue *queue)
{
	if (!queue)
		return ;
	free(queue);
}

void	queue_clear(t_queue **root)
{
	t_queue	*ref;
	t_queue	*cur;

	if (!root || !root[0])
		return ;
	ref = root[0];
	while (ref-> next)
	{
		cur = ref;
		ref = ref->next;
		queue_delone(cur);
	}
	queue_delone(ref);
	*root = NULL;
}
