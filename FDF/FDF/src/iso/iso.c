/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:26:10 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/31 19:17:42 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iso.h"

static t_coord	*scale_and_center(int x, int y, t_map *map, t_coord *co)
{
	int	scale_width;
	int	scale_height;
	int	scale;

	if (map->scale_factor == -map->width || map->scale_factor == -map->height)
		map->scale_factor = 0;
	scale_width = WIDTH / (map->width + map->scale_factor);
	scale_height = HEIGHT / (map->height + map->scale_factor);
	if (map->height > map->width)
		scale = scale_height;
	else
		scale = scale_width;
	co->x = x * scale;
	co->y = y * scale;
	co->x -= (map->width - 1) / 2 * scale;
	co->y -= (map->height - 1) / 2 * scale;
	if (map->width % 2 == 0)
		co->x -= scale / 2;
	if (map->height % 2 == 0)
		co->y -= scale / 2;
	return (co);
}

static t_coord	*first_rotation(t_coord *co, t_map map)
{
	double	angle;
	double	dx;
	double	dy;

	angle = map.angle * PI / 180;
	dx = co->x * cos(angle) - co->y * sin(angle);
	dy = co->y * cos(angle) + co->x * sin(angle);
	co->x = dx;
	co->y = dy;
	return (co);
}

static t_coord	*second_rotation(t_coord *co)
{
	co->y = co->y / 2;
	return (co);
}

static t_coord	*add_height(int x, int y, t_coord *co, t_map map)
{
	int	height;

	height = map.map[y * map.width + x];
	co->y -= height * map.tile_height * map.steepness;
	return (co);
}

// First, scale and center the object on the origin.
// Rotate the image to get the isometric perspective, then add height.
t_coord	*cart_to_iso(int x, int y, t_map *map)
{
	t_coord	*co;

	co = malloc(sizeof(t_coord));
	if (co == NULL)
		return (NULL);
	co = scale_and_center(x, y, map, co);
	co = first_rotation(co, *map);
	co = second_rotation(co);
	co = add_height(x, y, co, *map);
	return (co);
}
