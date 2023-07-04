/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:55 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:19:56 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

/// @brief Allocate and initialize the minimap and associated structures. 
/// One time operations only.
/// @param game The main game struct.
void	init_minimap(t_game *game)
{
	t_mini	*mini;
	t_map	*map;

	allocate_minimap(game);
	mini = game->minimap;
	map = game->map;
	mini->wall_color = 0xC19A6BFF;
	mini->border_color = 0xFFFFFFFF;
	mini->floor_color = 0x008000FF;
	mini->spawn_color = 0xFFFF00FF;
	mini->player_color = 0xF0000080;
	if (map->width <= map->height)
		mini->tile_size = mini->minimap->height / map->height;
	else
		mini->tile_size = mini->minimap->width / map->width;
	mini->map_scale_factor = mini->tile_size / (float)game->unit_size;
	mini->mini_x = (size_t)round(game->player->x * mini->map_scale_factor);
	mini->mini_y = (size_t)round(game->player->y * mini->map_scale_factor);
}

/// @brief Allocate space for the minimap array and its images.
/// @param game The main game struct.
void	allocate_minimap(t_game *game)
{
	game->minimap = (t_mini *)ft_calloc(1, sizeof(t_mini));
	if (game->minimap == NULL)
		clear_and_exit(game, EXIT_FAILURE, "Allocation error");
	game->minimap->minimap = mlx_new_image(game->mlx, HEIGHT, HEIGHT);
	if (game->minimap->minimap == NULL)
		clear_and_exit(game, EXIT_FAILURE, "Allocation error");
	game->minimap->ray_holder = mlx_new_image(game->mlx, HEIGHT, HEIGHT);
	if (game->minimap->ray_holder == NULL)
		clear_and_exit(game, EXIT_FAILURE, "Allocation error");
	game->minimap->player_icon = mlx_new_image(game->mlx, 13, 13);
	if (game->minimap->player_icon == NULL)
		clear_and_exit(game, EXIT_FAILURE, "Allocation error");
}
