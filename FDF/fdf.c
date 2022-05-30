/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:22:17 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/30 19:01:45 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
https://github.com/codam-coding-college/MLX42/wiki/Images
*/

#include "fdf.h"
#include <stdio.h>
#include <math.h>
# include "src/line/line.h"
# include "src/iso/iso.h"
# include "src/map/map.h"
# include "src/math/math.h"

void	free_all(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	free(mlx->map->map);
	free(mlx);
}

// 53 == ESC, 7 == x, 6 == z
int	keyhooks(int keycode, t_mlx *mlx)
{
	if(keycode == 7)
	{
		mlx->map->steepness += 0.1;
	}
	if(keycode == 6)
	{
		mlx->map->steepness -= 0.1;
	}
	if (keycode == 53)
	{
		free_all(mlx);
		// system("leaks fdf");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_window_button(t_mlx *mlx)
{
	free_all(mlx);
	// system("leaks fdf");
	exit(EXIT_SUCCESS);
}


void	image_pixel_put(t_mlx_image img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (x * (img.bits_per_pixel / 8) + y * img.line_length);
	*(unsigned int *)dst = color;
}

// void	draw_map(t_mlx mlx);
void	draw_map(t_mlx mlx, int m, int n, int direction);

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		printf("%s\n", "Incorrect argument");
		exit(EXIT_FAILURE);
	}

	set_w_h(argv, &map);
	if (map.height == 0 || map.width == 0)
		exit(EXIT_FAILURE);

	fill_map(argv, &map);
	set_map_values(&map);
	print_map(map);

	t_mlx *mlx = init_mlx();
	if(mlx == NULL || mlx->mlx == NULL)
		exit(EXIT_FAILURE);
	mlx->map = &map;

	// Add axes to image
	t_coord a1 = {WIDTH / 2, 0};
	t_coord a2 = {WIDTH / 2, HEIGHT};
	t_coord b1 = {0, HEIGHT / 2};
	t_coord b2 = {WIDTH, HEIGHT / 2};
	image_draw_line(*mlx, a1, a2, BLUE);
	image_draw_line(*mlx, b1, b2, BLUE);
	// end axes

	// draw_map(*mlx);
	draw_map(*mlx, map.height, map.width, 1);
	draw_map(*mlx, map.width, map.height, 0);

	mlx_hook(mlx->win, 17, 0, close_window_button, mlx);
	mlx_key_hook(mlx->win, keyhooks, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	mlx_loop(mlx->mlx);

	return (EXIT_SUCCESS);
}

void	draw_map(t_mlx mlx, int m, int n, int direction)
{
	int i;
	int j;
	t_coord start;
	t_coord *end;

	end = cart_to_iso(0, 0, *mlx.map);
	iso_add_height(0, 0, *mlx.map, end);
	i = 0;
	while(i < m)
	{
		j = 0;
		while(j < n)
		{
			start = *end;
			free(end);
			end = draw_map_get_iso(mlx, i, j, direction);
			if (j++ == 0 && i != 0)
				continue ;
			image_draw_line(mlx, start, *end, 0x00FF0000);
		}
		printf("\n");
		i++;
	}
	free(end);
}

//static
t_coord *draw_map_get_iso(t_mlx mlx, int i, int j, int direction)
{
	t_coord *end;

	if(direction)
	{
		end = cart_to_iso(j, i, *mlx.map);
		iso_add_height(j, i, *mlx.map, end);
		printf("%2d:(%4d,%4d) ", mlx.map->map[j + i * mlx.map->width], end->x, end->y);
	}
	else
	{
		end = cart_to_iso(i, j, *mlx.map);
		iso_add_height(i, j, *mlx.map, end);
	}
	return (end);
}

t_mlx	*init_mlx()
{
	t_mlx* mlx;

	mlx = malloc(sizeof(t_mlx));
	if(mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	if(mlx->mlx == NULL)
		return (NULL);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FDF by Thibauld Nuyten");
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	mlx->swap_img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->swap_img.addr = mlx_get_data_addr(mlx->swap_img.img, &mlx->swap_img.bits_per_pixel, &mlx->swap_img.line_length, &mlx->swap_img.endian);

	return (mlx);
}
