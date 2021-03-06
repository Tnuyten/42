/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:28:05 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/30 18:42:18 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

#include <stdio.h>

void draw_horizontal_line(t_mlx_image img, t_coord start, t_coord end, int color)
{
	int x;

	if(start.x > end.x)
	{
		draw_horizontal_line(img, end, start, color);
		return ;
	}
	x = start.x;
	if(end.y == start.y)
	{
		while(x < end.x)
		{
			image_pixel_put(img, x, start.y, color);
			x++;
		}
		return;
	}
	else
	{
		printf("that's not a horizontal line");
	}
}

void draw_vertical_line(t_mlx_image img, t_coord start, t_coord end, int color)
{
	int y;

	if(start.y > end.y)
	{
		draw_vertical_line(img, end, start, color);
		return ;
	}
	y = start.y;
	if(end.x == start.x)
	{
		while(y < end.y)
		{
			image_pixel_put(img, start.x, y, color);
			y++;
		}
		return ;
	}
	else
	{
		printf("that's not a vertical line");
	}
}

// // m < 1
// void image_draw_small_m_line(t_mlx_image img, t_coord start, t_coord end, int color)
// {
// 	int dx;
// 	int dy;
// 	int x_steps;
//
// 	printf("%s\n", "small m");
//
// 	if(start.y > end.y)
// 	{
// 		image_draw_small_m_line(img, end, start, color);
// 		return ;
// 	}
// 	dx = end.x - start.x;
// 	dy = end.y - start.y;
// 	x_steps = dy / dx;
// 	int x_steps_rem = dy % dx;
// 	printf("rem: %d\n", x_steps_rem);
// 	image_pixel_put(img, start.x, start.y, color);
//
// 	printf("x_steps: %d. Color: 0x%08X\n", x_steps, color);
//
// 	while(start.y < end.y)
// 	{
// 		printf("start.y: %3d. end.y: %3d. (end.y-start.y): %d. (end.y-start.y) %% x_steps: %d.\n", start.y, end.y, end.y-start.y, (end.y-start.y) % x_steps);
// 		printf("start.x: %3d. end.x: %3d. steps: %d\n", start.x, end.x, x_steps);
// 		start.y++;
// 		if(end.y != start.y && (end.y - start.y) % x_steps == 0)
// 		{
// 			if(start.x < end.x)
// 				start.x++;
// 			else
// 				start.x--;
// 		}
// 		image_pixel_put(img, start.x, start.y, color);
// 	}
// }
//
// // m >= 1
// void image_draw_big_m_line(t_mlx_image img, t_coord start, t_coord end, int color)
// {
// 	int dx;
// 	int dy;
// 	int y_steps;
//
// 	printf("%s\n", "BIG M");
//
// 	if(start.x > end.x)
// 	{
// 		image_draw_big_m_line(img, end, start, color);
// 		return ;
// 	}
// 	dx = end.x - start.x;
// 	dy = end.y - start.y;
// 	y_steps = dx / dy;
// 	image_pixel_put(img, start.x, start.y, color);
// 	while(start.x < end.x)
// 	{
// 		start.x++;
// 		if(end.x != start.x && (end.x - start.x) % y_steps == 0)
// 		{
// 			if(start.y < end.y)
// 				start.y++;
// 			else
// 				start.y--;
// 		}
// 		image_pixel_put(img, start.x, start.y, color);
// 	}
// }

void image_draw_line(t_mlx mlx, t_coord start, t_coord end, int color)
{
	int dx;
	int dy;

	if(start.x > WIDTH || end.x > WIDTH || start.y > HEIGHT || end.y > HEIGHT)
	{
		return;
	}
	if(start.x < 0 || end.x < 0 || start.y < 0 || end.y < 0)
	{
		return;
	}

	dx = abs(end.x - start.x);
	dy = abs(end.y - start.y);
	if(dx == 0 && dy == 0)
		return;
	if(dx == 0)
		draw_vertical_line(mlx.img, start, end, color);
	else if(dy == 0)
		draw_horizontal_line(mlx.img, start, end, color);
	else
		image_draw_line_bresenham(mlx.img, start, end, color);
	// else if(dx >= dy)
	// 	image_draw_big_m_line(img, start, end, color);
	// else if(dy > dx)
	// 	image_draw_small_m_line(img, start, end, color);
}

void image_draw_line_bresenham(t_mlx_image img, t_coord start, t_coord end, int color)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int error;

	dx = abs(end.x - start.x);
	dy = -abs(end.y - start.y);
	sx = 1;
	sy = 1;
	if(start.x > end.x)
		sx = -1;
	if(start.y > end.y)
		sy = -1;
	error = dx + dy;
	while(1)
	{
		image_pixel_put(img, start.x, start.y, color);
		if(start.x == end.x && start.y == end.y)
			break;
		if(2*error >= dy)
		{
			if(start.x == end.x)
				break;
			error += dy;
			start.x += sx;
		}
		if(2*error <= dx)
		{
			if(start.y == end.y)
				break;
			error += dx;
			start.y += sy;
		}
	}
}
