/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:43:29 by tnuyten           #+#    #+#             */
/*   Updated: 2022/06/27 16:16:17 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_queue	*a;
	t_queue	*b;

	b = NULL;
	if (argc < 2)
		return (1);
	if (parse_input(&a, argc, argv))
	{
		ft_printf("%s\n", "Error");
		return (1);
	}
	if (has_duplicates(a))
	{
		ft_printf("%s\n", "Error");
		queue_clear(&a);
		return (1);
	}
	do_stack_operations(&a, &b);
	if (is_sorted(a))
		ft_printf("%s\n", "OK");
	else
		ft_printf("%s\n", "KO");
	queue_clear(&a);
	queue_clear(&b);
	return (0);
}

void	do_stack_operations(t_queue **a, t_queue **b)
{
	char			*line;
	t_func_single	func_s;
	t_func_multi	func_m;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			return ;
		func_s = get_single_stack_operation(line);
		func_m = get_multi_stack_func(line);
		if (func_s == NULL && func_m == NULL)
			return ;
		if (func_s != NULL)
			func_s(a);
		if (func_m != NULL)
			func_m(a, b);
	}
}

t_func_single	get_single_stack_operation(char *line)
{
	if (line[0] == 's' && line[1] == 'a')
		return (&sa);
	if (line[0] == 's' && line[1] == 'b')
		return (&sb);
	if (line[0] == 'r' && line[1] == 'a')
		return (&ra);
	if (line[0] == 'r' && line[1] == 'b')
		return (&rb);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		return (&rra);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		return (&rrb);
	return (NULL);
}

t_func_multi	get_multi_stack_func(char *line)
{
	if (line[0] == 'p' && line[1] == 'a')
		return (&pa);
	if (line[0] == 'p' && line[1] == 'b')
		return (&pb);
	if (line[0] == 's' && line[1] == 's')
		return (&ss);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		return (&rrr);
	if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		return (&rr);
	return (NULL);
}
