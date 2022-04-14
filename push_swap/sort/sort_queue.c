/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:28:43 by tnuyten           #+#    #+#             */
/*   Updated: 2022/04/14 15:35:01 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_queue.h"

#include <stdio.h> //#TODO REMOVE

void	sort(t_queue **a, t_queue **b)
{
	if (is_sorted(a[0]))
		return ;
	normalize(a);
	radix_sort(a, b);
}

void	radix_sort(t_queue **a, t_queue **b)
{
	size_t	siz;
	size_t	i;
	int		mask;
	int		j;

	mask = 1;
	j = 0;
	siz = queue_size(a[0]);
	while (j < binary_size(siz))
	{
		i = 0;
		while (i < siz)
		{
			// printf("%d %d %d\n", a[0]->number, mask, a[0]->number & mask);
			if ((a[0]->number & mask) != 0)
			{
				ra(a);
				printf("%s\n", "ra");
			}
			else
			{
				pb(a, b);
				printf("%s\n", "pb");
			}
			i++;
		}
		while (queue_size(b[0]) > 0)
		{
			pa(a, b);
			printf("%s\n", "pa");
		}
		mask = mask << 1; //why the hell did this almost work correctly with mask *= 10???
		j++;
	}
}

void	smallest_first(t_queue **a, t_queue **b)
{
	t_queue	*smallest;
	int		smallest_index;
	int		half_siz;

	while (queue_size(a[0]) > 0)
	{
		smallest = find_smallest(a);
		smallest_index = queue_index(a, smallest);
		half_siz = queue_size(a[0]) >> 1;
		while (a[0] != smallest)
		{
			if (smallest_index <= half_siz)
			{
				ra(a);
				printf("%s\n", "ra");
			}
			else
			{
				rra(a);
				printf("%s\n", "rra");
			}
		}
		pb(a, b);
		printf("%s\n", "pb");
	}
	while (queue_size(b[0]) > 0)
	{
		pa(a, b);
		printf("%s\n", "pa");
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
	if (queue_size(a[0]) != 3)
	{
		printf("%s\n", "wrong size for sort three");
		return ;
	}
	if (is_sorted(a[0])) // --> 1 2 3
		return ;
	if (first > second && second > third) // --> 3 2 1
	{
		sa(a);
		rra(a);
		printf("%s\n%s\n", "sa", "rra");
	}
	if (first > second && second < third && first < third) // --> 2 1 3
	{
		sa(a);
		printf("%s\n", "sa");
	}
	if (first > second && second < third && first > third) // --> 3 1 2
	{
		ra(a);
		printf("%s\n", "ra");
	}
	if (first < second && second > third && first < third) // --> 1 3 2
	{
		sa(a);
		ra(a);
		printf("%s\n%s\n", "sa", "ra");
	}
	if (first < second && second > third && first > third) // --> 2 3 1
	{
		rra(a);
		printf("%s\n", "rra");
	}
}

void	sort_five(t_queue **a, t_queue **b)
{
	int	a_top;
	int	b_top;

	pb(a, b);
	pb(a, b);
	printf("%s\n%s\n", "pb", "pb");
	sort_three(a);
	a_top = a[0]->number;
	b_top = b[0]->number;
	//crap
}
