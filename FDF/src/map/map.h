/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:29:12 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/24 18:58:41 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../../fdf.h"
# include <math.h>
# include "../iso/iso.h"

int		*str_to_int_arr(char *line, int *width);
void	set_w_h(char **argv, t_map *map);
void	fill_map(char **argv, t_map *map);
void	set_map_values(t_map *map);


// DEBUG
void	print_map(t_map map);

#endif