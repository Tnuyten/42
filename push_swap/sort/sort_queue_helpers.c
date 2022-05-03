/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_queue_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:28:46 by tnuyten           #+#    #+#             */
/*   Updated: 2022/04/15 19:17:13 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_queue_helpers.h"

int	binary_size(int num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num = num >> 1;
		count++;
	}
	return (count);
}

t_queue	*find_smallest(t_queue **root)
{
	int		num;
	t_queue	*smallest;
	t_queue	*root_top;

	if (queue_size(root[0]) == 0)
		return (NULL);
	root_top = root[0];
	smallest = root_top;
	num = root_top->number;
	while (root_top->next != NULL)
	{
		root_top = root_top->next;
		if (root_top->number < num)
		{
			smallest = root_top;
			num = root_top->number;
		}
	}
	return (smallest);
}

int	is_sorted(t_queue *root)
{
	int	num;

	if (!root)
		return (1);
	while (root->next != NULL)
	{
		num = root->number;
		root = root->next;
		if (num > root->number)
		{
			return (0);
		}
	}
	return (1);
}

void	normalize(t_queue **root)
{
	t_queue	*input;
	t_queue	*copy;
	t_queue	*copy_tmp;
	int		j;

	copy = queue_copy(root[0]);
	normal_sort(&copy);
	input = root[0];
	while (input != NULL)
	{
		j = 0;
		copy_tmp = copy;
		while (copy_tmp != NULL)
		{
			if (input->number == copy_tmp->number)
			{
				input->number = j;
				break ;
			}
			j++;
			copy_tmp = copy_tmp->next;
		}
		input = input->next;
	}
	queue_clear(&copy);
}

void	normal_sort(t_queue **root)
{
	t_queue	*tmp;
	int		save;

	while (!is_sorted(root[0]))
	{
		tmp = root[0];
		while (tmp->next != NULL)
		{
			if (tmp->number > tmp->next->number)
			{
				save = tmp->number;
				tmp->number = tmp->next->number;
				tmp->next->number = save;
			}
			tmp = tmp->next;
		}
	}
}
