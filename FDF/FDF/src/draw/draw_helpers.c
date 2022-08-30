/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:25:51 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/30 21:25:51 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

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

void	redraw(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	clear_image(*mlx);
	draw_map(*mlx, mlx->map->height, mlx->map->width, 1);
	draw_map(*mlx, mlx->map->width, mlx->map->height, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
