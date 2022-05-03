/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_queue_helpers_more.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:12:42 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/03 18:00:46 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_queue_helpers_more.h"

#include "../debug.h"

int get_largest_node_lower_than_target(t_queue **a, t_queue *target)
{
	t_queue*	head;
	int			largest;
	int			largest_index;
	int			index;

	largest = -1;
	head = a[0];
	index = 0;
	largest_index = 0;
	while (head != NULL)
	{
		if (head->number < target->number)
		{
			if (head->number > largest)
			{
				largest = head->number;
				largest_index = index;
			}
		}
		index++;
		head = head->next;
	}

	if(largest == -1)
	{
		return -1;
	}

	return (largest_index);
}

// Returns the index of the position where target needs to be inserted into A.
// Queue A will always have at least 3 elements, and is sorted,
// though possibly rotated.
int find_insert_location(t_queue **a, t_queue *target)
{
	int index;
	int i;

	index = get_largest_node_lower_than_target(a, target);
	if(index == -1) // If there was no number lower than the target number in the list,
					// so get the lowest number instead. The number will have to be inserted
					// *before* the node found instead of after, so return index - 1;
	{
		i = 0;
		t_queue* lowest = queue_get_node(a, i++);
		while(lowest == NULL)
		{
			lowest = queue_get_node(a, i++);
		}
		index = queue_index(a, lowest) - 1;
	}

	return index;
}

void rotate_efficiently(t_queue **a, int index)//, t_queue* target)
{
	int i;
	int qs;

	qs = queue_size(a[0]);
	if (index == qs - 1)
		return;
	index++;
	if(index > qs >> 1)
	{
		i = qs;
		while(i > index)
		{
			rra(a);
			ft_printf("%s\n", "rra");
			i--;
		}
	}
	else
	{
		i = 0;
		while(i < index)
		{
			ra(a);
			ft_printf("%s\n", "ra");
			i++;
		}
	}
}