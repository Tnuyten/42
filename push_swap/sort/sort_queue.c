/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:28:43 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/03 18:02:57 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_queue.h"

#include "../debug.h"

void	sort(t_queue **a, t_queue **b)
{
	size_t q_siz;

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
	}
	else if(q_siz > 3 && q_siz < 25)
	{
		sort_small(a, b);
	}
	else
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
			i++;
		}
		while (queue_size(b[0]) > 0)
		{
			pa(a, b);
			ft_printf("%s\n", "pa");
		}
		mask = mask << 1; //why did this almost work correctly with mask *= 10?
						  //Except for the 2nd iteration?
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
				ft_printf("%s\n", "ra");
			}
			else
			{
				rra(a);
				ft_printf("%s\n", "rra");
			}
		}
		pb(a, b);
		ft_printf("%s\n", "pb");
	}
	while (queue_size(b[0]) > 0)
	{
		pa(a, b);
		ft_printf("%s\n", "pa");
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
		ft_printf("%s\n", "wrong size for sort three");
		return ;
	}
	if (is_sorted(a[0])) // --> 1 2 3
		return ;
	if (first > second && second > third) // --> 3 2 1
	{
		sa(a);
		rra(a);
		ft_printf("%s\n%s\n", "sa", "rra");
	}
	if (first > second && second < third && first < third) // --> 2 1 3
	{
		sa(a);
		ft_printf("%s\n", "sa");
	}
	if (first > second && second < third && first > third) // --> 3 1 2
	{
		ra(a);
		ft_printf("%s\n", "ra");
	}
	if (first < second && second > third && first < third) // --> 1 3 2
	{
		sa(a);
		ra(a);
		ft_printf("%s\n%s\n", "sa", "ra");
	}
	if (first < second && second > third && first > third) // --> 2 3 1
	{
		rra(a);
		ft_printf("%s\n", "rra");
	}
}

void	sort_small(t_queue **a, t_queue **b)
{
	while (queue_size(a[0]) > 3)
	{
		pb(a, b);
		ft_printf("%s\n", "pb");
	}
	sort_three(a);
	while(queue_size(b[0]) > 0)
	{
		int insert_pos = find_insert_location(a, b[0]);

		// print_queue("az", *a);
		// print_queue("bz", *b);
		// ft_printf("Insert pos: %d\n", insert_pos);

		rotate_efficiently(a, insert_pos);
		pa(a, b);
		ft_printf("%s\n", "pa");
	}

	// rotate_efficiently(a, queue_index(a, queue_get_node(a, 0)));
	while(a[0]->number != 0)
	{
		ra(a);
		ft_printf("%s\n", "ra");
	}
	// print_queue("az", *a);
	// print_queue("bz", *b);
}
