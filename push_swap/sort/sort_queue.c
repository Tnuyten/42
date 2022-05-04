/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:28:43 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/04 12:41:28 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_queue.h"

void	sort(t_queue **a, t_queue **b)
{
	size_t	q_siz;

	q_siz = queue_size(a[0]);
	if (is_sorted(a[0]))
		return ;
	normalize(a);
	if (q_siz < 3)
	{
		ra(a);
		ft_printf("%s\n", "ra");
	}
	else if (q_siz == 3)
	{
		sort_three(a);
		rotate_efficiently(a, queue_index(a, queue_get_node(a, 0)) - 1);
	}
	else if (q_siz > 3 && q_siz < 50)
	{
		sort_small(a, b);
	}
	else
		radix_sort(a, b);
}

//why did this almost work correctly with mask *= 10?
//Except for the 2nd iteration?
void	radix_sort(t_queue **a, t_queue **b)
{
	int	i;
	int	mask;
	int	j;

	mask = 1;
	j = 0;
	while (j < binary_size(queue_size(a[0])))
	{
		i = 0;
		while (i < queue_size(a[0]))
		{
			ra_or_pb(a, b, mask);
			i++;
		}
		while (queue_size(b[0]) > 0)
		{
			pa(a, b);
			ft_printf("%s\n", "pa");
		}
		mask = mask << 1;
		j++;
	}
}

void	ra_or_pb(t_queue **a, t_queue **b, int mask)
{
	if ((a[0]->number & mask) != 0)
	{
		ra(a);
		ft_printf("%s\n", "ra");
	}
	else
	{
		pb(a, b);
		ft_printf("%s\n", "pb");
	}
}

void	sort_three(t_queue **a)
{
	int	first;
	int	second;
	int	third;

	first = a[0]->number;
	second = a[0]->next->number;
	third = a[0]->next->next->number;
	if (is_sorted(a[0]))
		return ;
	if (first > second && second > third)
	{
		sa(a);
		ft_printf("%s\n", "sa");
	}
	if (first > second && second < third && first < third)
	{
		sa(a);
		ft_printf("%s\n", "sa");
	}
	if (first < second && second > third && first < third)
	{
		sa(a);
		ft_printf("%s\n", "sa");
	}
}

void	sort_small(t_queue **a, t_queue **b)
{
	int	insert_pos;

	while (queue_size(a[0]) > 3)
	{
		pb(a, b);
		ft_printf("%s\n", "pb");
	}
	sort_three(a);
	while (queue_size(b[0]) > 0)
	{
		insert_pos = find_insert_location(a, b[0]);
		rotate_efficiently(a, insert_pos);
		pa(a, b);
		ft_printf("%s\n", "pa");
	}
	rotate_efficiently(a, queue_index(a, queue_get_node(a, 0)) - 1);
}
