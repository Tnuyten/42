/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:48:30 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/03 18:53:18 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue_get.h"

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

t_queue	*queue_get_node(t_queue **root, int num)
{
	t_queue	*root_top;
	int		index;

	root_top = root[0];
	index = 0;
	while (root_top != NULL)
	{
		if (root_top->number == num)
			return (root_top);
		index++;
		root_top = root_top->next;
	}
	return (NULL);
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
