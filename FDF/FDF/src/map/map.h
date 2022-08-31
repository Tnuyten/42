/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:29:12 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/31 17:15:02 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include "../../fdf.h"
# include "../iso/iso.h"
# include "../math/math.h"

void	make_map(char **argv, t_map *map);
void	set_width(char *line, t_map *map);
void	set_w_h(char **argv, t_map *map);

#endif