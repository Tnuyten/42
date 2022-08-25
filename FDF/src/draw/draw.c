/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:35:42 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/25 18:17:40 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	redraw(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	clear_image(*mlx);
	draw_map(*mlx, mlx->map->height, mlx->map->width, 1);
	draw_map(*mlx, mlx->map->width, mlx->map->height, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

t_coord	*get_coordinates(int x, int y, t_map map)
{
	t_coord	*right;
	t_coord	*left;
	t_coord	*top;
	t_coord	*bottom;
	t_coord	*co;

	co = cart_to_iso(x, y, map);
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
	co = add_offset(co, map);
	return (co);
}

void	draw_map(t_mlx mlx, int m, int n, int direction)
{
	int		i;
	int		j;
	t_coord	start;
	t_coord	*end;

	end = get_coordinates(0, 0, *mlx.map);
	i = 0;
	while (i < m)
	{
		j = 0;
		while (j < n)
		{
			start = *end;
			free(end);
			if (direction)
				end = get_coordinates(j, i, *mlx.map);
			else
				end = get_coordinates(i, j, *mlx.map);
			if (j++ == 0 && i != 0)
				continue ;
			image_draw_line(mlx, start, *end, 0x00FF0000);
		}
		i++;
	}
	free(end);
}

void	clear_image(t_mlx mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			image_pixel_put(mlx.img, j++, i, 0x00000000);
		}
		i++;
	}
}

void	image_pixel_put(t_mlx_image img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (x * (img.bits_per_pixel / 8) + y * img.line_length);
	*(unsigned int *)dst = color;
}
