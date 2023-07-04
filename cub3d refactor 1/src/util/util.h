/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:29 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:20:30 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "../cub3d.h"

int		is_player_spawn(char c);
int		cell_is_edge(t_map *map, size_t x, size_t y);
int		out_of_bounds(t_map *map, size_t x, size_t y);
size_t	min(size_t a, size_t b);

#endif
