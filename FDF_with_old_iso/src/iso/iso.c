/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:26:10 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/25 17:40:24 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iso.h"
#include "math.h"

#define PI 3.14159265

//First, scale and center the object on the origin.
// Rotate the image to get the isometric perspective, then add height.
t_coord	*cart_to_iso(int x, int y, t_map map)
{
	t_coord	*co;

	co = malloc(sizeof(t_coord));
	if (co == NULL)
		return (NULL);
	co = scale_and_center(x, y, map, co);
	co = first_rotation(co, map);
	co = second_rotation(co);
	co = add_height(x, y, co, map);
	return (co);
}

t_coord	*scale_and_center(int x, int y, t_map map, t_coord *co)
{
	int	scale_width;
	int	scale_height;

	scale_width = WIDTH / (map.width - 1);
	scale_height = HEIGHT / (map.height - 1);
	co->x = x * scale_height;
	co->y = y * scale_height;
	co->x -= (map.width - 1) / 2 * scale_width;
	co->y -= (map.height - 1) / 2 * scale_height;
	if (map.width % 2 == 0)
	{
		co->x -= scale_width / 2;
	}
	if (map.height % 2 == 0)
	{
		co->y -= scale_height / 2;
	}
	return (co);
}

t_coord	*first_rotation(t_coord *co, t_map map)
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

t_coord	*second_rotation(t_coord *co)
{
	co->y = co->y / 2;
	return (co);
}

t_coord	*add_height(int x, int y, t_coord *co, t_map map)
{
	int	height;

	height = map.map[x + y * map.width];
	co->y -= height * map.tile_height * map.steepness;
	return (co);
}

// t_coord	*cart_to_iso(int x, int y, t_map map)
// {
// 	t_coord	*co;
// 	int		height;
//
// 	co = malloc(sizeof(t_coord));
// 	co->x = map.iso_x_origin + (x - y) * map.tile_width_half;
// 	co->y = map.iso_y_origin + (x + y) * map.tile_length_half;
// 	height = map.map[x + y * map.width];
// 	co->y -= height * map.tile_height * map.steepness;
//
// 	return (co);
// }
