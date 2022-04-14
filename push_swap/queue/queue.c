/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:35:44 by tnuyten           #+#    #+#             */
/*   Updated: 2022/04/14 15:14:29 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*queue_new(int num)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->number = num;
	queue->next = NULL;
	return (queue);
}

void	queue_addback(t_queue **root, t_queue *new_queue)
{
	t_queue	*tmp;

	if (!root[0] || !root)
		return ;
	if (root[0] == NULL)
	{
		root[0] = new_queue;
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
	if (!root[0] || !root || !new_queue)
		return ;
	new_queue->next = root[0];
	root[0] = new_queue;
}

t_queue	*queue_last(t_queue *queue)
{
	if (!queue)
		return (NULL);
	while (queue->next)
		queue = queue->next;
	return (queue);
}

int	queue_size(t_queue *queue)
{
	int	count;

	count = 0;
	if (!queue)
		return (0);
	while (queue->next != NULL)
	{
		queue = queue->next;
		count++;
	}
	return (count + 1);
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

int	queue_index(t_queue **root, t_queue *target)
{
	t_queue	*root_top;
	int		index;

	root_top = root[0];
	index = 0;
	while (root_top != NULL)
	{
		if (root_top == target)
			return (index);
		index++;
		root_top = root_top->next;
	}
	return (-1);
}

t_queue	*queue_copy(t_queue *root)
{
	t_queue	*cpy;

	if (!root)
		return (NULL);
	cpy = queue_new(root->number);
	root = root->next;
	while (root != NULL)
	{
		queue_addback(&cpy, queue_new(root->number));
		root = root->next;
	}
	return (cpy);
}
