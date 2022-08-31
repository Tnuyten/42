/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:43:22 by tnuyten           #+#    #+#             */
/*   Updated: 2022/06/27 16:08:33 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "../get_next_line/get_next_line.h"

typedef void	(*t_func_single)(t_queue **);
typedef void	(*t_func_multi)(t_queue **, t_queue **);

void			do_stack_operations(t_queue **a, t_queue **b);
t_func_single	get_single_stack_operation(char *line);
t_func_multi	get_multi_stack_func(char *line);

#endif