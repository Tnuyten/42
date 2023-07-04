/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:57 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:19:58 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

/// @brief Place a tile on the minimap
/// @param mini The minimap struct
/// @param x The x coordinate of the map (t_map)
/// @param y The y coordinate of the map (t_map)
/// @param map The map struct.
void	place_tile(t_mini *mini, size_t x, size_t y, t_map *map)
{
	size_t	yy;
	size_t	xx;
	size_t	x_start;
	size_t	y_start;

	x_start = x * mini->tile_size;
	y_start = y * mini->tile_size;
	yy = y_start;
	while (yy < y_start + mini->tile_size && yy < mini->minimap->height)
	{
		xx = x_start;
		while (xx < x_start + mini->tile_size && xx < mini->minimap->width)
		{
			if (map->map[y][x] == '1')
				mlx_put_pixel(mini->minimap, xx, yy, mini->wall_color);
			else if (map->map[y][x] == '0' || map->map[y][x] == '8')
				mlx_put_pixel(mini->minimap, xx, yy, mini->floor_color);
			else if (is_player_spawn(map->map[y][x]))
				mlx_put_pixel(mini->minimap, xx, yy, mini->spawn_color);
			xx++;
		}
		yy++;
	}
}

void	make_minimap(t_game *game)
{
	size_t		x;
	size_t		y;
	mlx_image_t	*icon;

	icon = game->minimap->player_icon;
	if (game->minimap_enabled == false)
		return ;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < ft_strlen(game->map->map[y]))
		{
			place_tile(game->minimap, x, y, game->map);
			x++;
		}
		y++;
	}
	update_minimap_coordinates(game);
	draw_ray_on_holder(game);
	draw_icon(game);
	mlx_image_to_window(game->mlx, game->minimap->minimap, WIDTH, 0);
	mlx_image_to_window(game->mlx, icon, WIDTH + icon_x(game), icon_y(game));
	mlx_image_to_window(game->mlx, game->minimap->ray_holder, WIDTH, 0);
}
