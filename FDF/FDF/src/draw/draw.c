/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:35:42 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/30 21:11:16 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static t_coord	*add_offset(t_coord *co, t_map map)
{
	co->x += map.x_offset;
	co->y += map.y_offset;
	return (co);
}

static t_coord	*recenter(t_map map, t_coord *co)
{
	t_coord	*right;
	t_coord	*left;
	t_coord	*top;
	t_coord	*bottom;

	right = cart_to_iso(map.width - 1, 0, map);
	left = cart_to_iso(0, map.height - 1, map);
	bottom = cart_to_iso(map.width - 1, map.height - 1, map);
	top = cart_to_iso(0, 0, map);
	if (left->x < 0)
		co->x -= left->x;
	if (right->x > WIDTH)
		co->x -= right->x - WIDTH;
	if (top->y < 0)
		co->y -= top->y;
	if (bottom->y > HEIGHT)
		co->y -= bottom->y - HEIGHT;
	free(right);
	free(left);
	free(top);
	free(bottom);
	return (co);
}

static t_coord	*get_coordinates(int x, int y, t_map map, int direction)
{
	t_coord	*co;

	if (direction)
	{
		co = cart_to_iso(x, y, map);
	}
	else
	{
		co = cart_to_iso(y, x, map);
	}
	co = recenter(map, co);
	co = add_offset(co, map);
	return (co);
}

static int	get_color(int i, int j, int direction, t_mlx mlx)
{
	int	color;

	if (direction)
		color = mlx.map->color_map[i * mlx.map->width + j];
	else
		color = mlx.map->color_map[j * mlx.map->width + i];
	if (color == 0)
		color = 0x00123456;
	return (color);
}

void	draw_map(t_mlx mlx, int m, int n, int direction)
{
	int		i;
	int		j;
	t_coord	start;
	t_coord	*end;
	int		color;

	end = get_coordinates(0, 0, *mlx.map, direction);
	i = 0;
	while (i < m)
	{
		j = 0;
		while (j < n)
		{
			start = *end;
			free(end);
			end = get_coordinates(j, i, *mlx.map, direction);
			color = get_color(i, j, direction, mlx);
			if (j++ == 0 && i != 0)
				continue ;
			image_draw_line(mlx, start, *end, color);
		}
		i++;
	}
	free(end);
}
