/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:26:10 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/27 15:49:32 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iso.h"
#include <math.h>

int list_max(t_map map)
{
	int i = 0;
	int max = 0;

	while(i < map.width * map.height)
	{
		if(map.map[i] > max)
		{
			max = map.map[i];
		}
		i++;
	}
	return (max);
}

t_coord *cart_to_iso(int x, int y, t_map map)
{
	t_coord	*co;

	co = malloc(sizeof(t_coord));
	co->x = map.iso_x_origin + (x - y) * map.tile_width_half;
	co->y = map.iso_y_origin + (x + y) * map.tile_length_half;
	return (co);
}

void iso_add_height(int x, int y, t_map map, t_coord *co)
{
	int height = map.map[x + y * map.width];
	co->y -= height * map.tile_height * map.steepness;
}