/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:29:12 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/30 21:23:42 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include "../../fdf.h"
# include "../iso/iso.h"
# include "../math/math.h"

void	make_map(char **argv, t_map *map);
void	set_width(char **argv, t_map *map);
void	set_w_h(char **argv, t_map *map);

#endif