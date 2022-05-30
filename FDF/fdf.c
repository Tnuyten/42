/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:22:17 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/30 14:01:44 by tnuyten          ###   ########.fr       */
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

int max(int a, int b)
{
	if(a >= b)
		return a;
	return b;
}

int min(int a, int b)
{
	if(a <= b)
		return a;
	return b;
}

int change_steepness(int keycode, t_mlx *mlx)
{
	printf("%d\n", keycode);
	printf("%p\n", mlx);
	printf("%p\n", mlx->map);
	printf("%f\n", mlx->map->steepness);
	if(keycode == 7)
	{
		mlx->map->steepness += 0.1;
	}
	if(keycode == 6)
	{
		mlx->map->steepness -= 0.1;
	}
	return 0;
}

//ESC == 53
int	close_window_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_window_button(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
}

void	image_pixel_put(t_mlx_image img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (x * (img.bits_per_pixel / 8) + y * img.line_length);
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		printf("%s\n", "Incorrect argument");
		exit(EXIT_FAILURE);
	}

	// set_w_h(argv, &map);
	// if (map.height == 0 || map.width == 0)
	// 	exit(EXIT_FAILURE);
	fill_map(argv, &map);
	set_map_values(&map);

	printf("%s\n", "=====MAP=====");
	print_map(map);
	printf("%s\n", "=====MAP=====");

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

	int	i;
	int	j;
	t_coord start = {0,0};
	t_coord *co = cart_to_iso(0, 0, map);
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			start = *co;
			free(co);
			co = cart_to_iso(j, i, map);
			iso_add_height(j, i, map, co);
			printf("%2d:(%4d,%4d)", map.map[j + i * map.width], co->x, co->y);
			if (j == 0 && i != 0)
			{
				j++;
				continue ;
			}
			image_draw_line(*mlx, start, *co, 0x00FF0000);
			j++;
		}
		printf("\n");
		i++;
	}
	free(co);
	co = cart_to_iso(0, 0, map);
	start.x = 0;
	start.y = 0;
	i = 0;
	while (i < map.width)
	{
		j = 0;
		while (j < map.height)
		{
			start = *co;
			free(co);
			co = cart_to_iso(i, j, map);
			iso_add_height(i, j, map, co);

			if (j == 0 && i != 0)
			{
				j++;
				continue;
			}
			image_draw_line(*mlx, start, *co, 0x00FF0000);
			j++;
		}
		i++;
	}
	free(co);

	mlx_hook(mlx->win, 17, 0, close_window_button, &mlx);
	mlx_key_hook(mlx->win, close_window_keypress, &mlx);
	mlx_key_hook(mlx->win, change_steepness, &mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	mlx_loop(mlx->mlx);

	free(&mlx);

	return (EXIT_SUCCESS);
}

t_map *init_map()
{
	return NULL;
}

t_mlx	*init_mlx()
{
	t_mlx* mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	if(mlx->mlx == NULL)
		return NULL;
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FDF by Thibauld Nuyten");
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);

	return (mlx);
}
