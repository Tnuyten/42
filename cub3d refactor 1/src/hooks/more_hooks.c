/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:09 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:19:10 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	reset(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key != MLX_KEY_R || keydata.modifier != 0)
		return ;
	find_player_spawn(game);
	if (game->minimap_enabled == true)
	{
		update_minimap_coordinates(game);
		game->minimap->player_icon->instances->x = WIDTH + icon_x(game);
		game->minimap->player_icon->instances->y = icon_y(game);
	}
}

void	move_left(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key != MLX_KEY_A || keydata.modifier != 0)
		return ;
	player_left(game);
	if (game->minimap_enabled == true)
	{
		update_minimap_coordinates(game);
		game->minimap->player_icon->instances->x = WIDTH + icon_x(game);
		game->minimap->player_icon->instances->y = icon_y(game);
	}
}

void	move_right(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key != MLX_KEY_D || keydata.modifier != 0)
		return ;
	player_right(game);
	if (game->minimap_enabled == true)
	{
		update_minimap_coordinates(game);
		game->minimap->player_icon->instances->x = WIDTH + icon_x(game);
		game->minimap->player_icon->instances->y = icon_y(game);
	}
}
