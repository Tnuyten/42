/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:57:17 by tnuyten           #+#    #+#             */
/*   Updated: 2022/04/14 15:33:14 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_proj/libft.h"
# include "queue/queue_operations_push.h"
# include "sort/sort_queue.h"

int	has_duplicates(t_queue *queue);
int	parse_input(t_queue **a, int argc, char **argv);

#endif