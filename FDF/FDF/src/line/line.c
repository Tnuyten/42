/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:28:05 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/25 16:56:07 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

static void	draw_horizontal_line(t_mlx_image img, t_coord start,
														t_coord end, int color)
{
	int	x;

	if (start.x > end.x)
	{
		draw_horizontal_line(img, end, start, color);
		return ;
	}
	x = start.x;
	if (end.y == start.y)
	{
		while (x < end.x)
		{
			image_pixel_put(img, x, start.y, color);
			x++;
		}
	}
}

static void	draw_vertical_line(t_mlx_image img, t_coord start,
														t_coord end, int color)
{
	int	y;

	if (start.y > end.y)
	{
		draw_vertical_line(img, end, start, color);
		return ;
	}
	y = start.y;
	if (end.x == start.x)
	{
		while (y < end.y)
		{
			image_pixel_put(img, start.x, y, color);
			y++;
		}
	}
}

static int	idlb_loop(t_line *line, t_coord *start, t_coord *end)
{
	if (start->x == end->x && start->y == end->y)
		return (1);
	if (2 * line->error >= line->dy)
	{
		if (start->x == end->x)
			return (1);
		line->error += line->dy;
		start->x += line->sx;
	}
	if (2 * line->error <= line->dx)
	{
		if (start->y == end->y)
			return (1);
		line->error += line->dx;
		start->y += line->sy;
	}
	return (0);
}

static void	image_draw_line_bresenham(t_mlx_image img, t_coord start,
														t_coord end, int color)
{
	t_line	line;

	line.dx = abs(end.x - start.x);
	line.dy = -abs(end.y - start.y);
	line.sx = 1;
	line.sy = 1;
	if (start.x > end.x)
		line.sx = -1;
	if (start.y > end.y)
		line.sy = -1;
	line.error = line.dx + line.dy;
	while (1)
	{
		image_pixel_put(img, start.x, start.y, color);
		if (idlb_loop(&line, &start, &end))
			break ;
	}
}

void	image_draw_line(t_mlx mlx, t_coord start, t_coord end, int color)
{
	int	dx;
	int	dy;

	if (start.x >= WIDTH || end.x >= WIDTH
		|| start.y >= HEIGHT || end.y >= HEIGHT)
		return ;
	if (start.x < 0 || end.x < 0 || start.y < 0 || end.y < 0)
		return ;
	dx = abs(end.x - start.x);
	dy = abs(end.y - start.y);
	if (dx == 0 && dy == 0)
		return ;
	if (dx == 0)
		draw_vertical_line(mlx.img, start, end, color);
	else if (dy == 0)
		draw_horizontal_line(mlx.img, start, end, color);
	else
		image_draw_line_bresenham(mlx.img, start, end, color);
}
