/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:21 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:20:22 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

/// @brief Set the player x and y to the center of the given tile.
/// @param game The main game struct.
/// @param map_x The map x coordinate where the player spawn was found.
/// @param map_y The map y coordinate where the player spawn was found.
static void	set_player_spawn(t_game *game, size_t map_x, size_t map_y)
{
	game->player->x = map_x * game->unit_size + game->unit_size / 2;
	game->player->y = map_y * game->unit_size + game->unit_size / 2;
	if (game->map->map[map_y][map_x] == 'E')
		game->player->angle = 0;
	if (game->map->map[map_y][map_x] == 'S')
		game->player->angle = M_PI / 2;
	if (game->map->map[map_y][map_x] == 'W')
		game->player->angle = M_PI;
	if (game->map->map[map_y][map_x] == 'N')
		game->player->angle = M_PI + M_PI / 2;
}

/// @brief Look through the map array for the player spawn symbol, then
/// set the player x and y to the center of that tile.
/// @param game The main game struct.
void	find_player_spawn(t_game *game)
{
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < ft_strlen(game->map->map[y]))
		{
			if (is_player_spawn(game->map->map[y][x]))
			{
				set_player_spawn(game, x, y);
				break ;
			}
			x++;
		}
		y++;
	}
}
