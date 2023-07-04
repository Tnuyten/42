/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:52 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/19 18:38:53 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	draw_ray_on_holder(t_game *game)
{
	t_player	*player;
	t_ray		**rays;
	size_t		x;
	float		dx;
	float		dy;

	if (game->minimap_enabled == false)
		return ;
	player = game->player;
	rays = game->cam->rays;
	clear_image(game->minimap->ray_holder, 0x00000000);
	x = 0;
	while (x < WIDTH)
	{
		dx = cos(rays[x]->ray_angle + player->angle);
		dy = sin(rays[x]->ray_angle + player->angle);
		draw_line(game, dx, dy, 0xFF00FFFF);
		x += 50;
	}
}

void	draw_line(t_game *game, float dx, float dy, size_t color)
{
	float	y;
	float	x;
	size_t	map_y;
	size_t	map_x;
	int		i;

	x = game->player->x * game->minimap->map_scale_factor;
	y = game->player->y * game->minimap->map_scale_factor;
	i = 0;
	while (i < 50)
	{
		map_y = y / game->minimap->tile_size;
		map_x = x / game->minimap->tile_size;
		if (x >= game->minimap->ray_holder->width || x < 0 || y < 0
			|| y >= game->minimap->ray_holder->height)
			break ;
		if (map_y < game->map->height
			&& map_x < game->map->row_lens[map_y]
			&& game->map->map[map_y][map_x] == '1')
			break ;
		mlx_put_pixel(game->minimap->ray_holder, x, y, color);
		x += dx;
		y += dy;
		i++;
	}
}
