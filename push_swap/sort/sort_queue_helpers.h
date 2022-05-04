/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_queue_helpers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:45:52 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/04 12:43:21 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_QUEUE_HELPERS_H
# define SORT_QUEUE_HELPERS_H

# include "../queue/queue.h"
# include "../queue/queue_get.h"

int		binary_size(int num);
t_queue	*find_smallest(t_queue **root);
int		is_sorted(t_queue *root);
void	normalize(t_queue **root);
void	normal_sort(t_queue **root);

#endif