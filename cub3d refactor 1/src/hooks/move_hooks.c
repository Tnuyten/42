/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:10 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:19:11 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	movement_hooks(mlx_key_data_t kd, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (kd.action == 0)
		return ;
	if (kd.key == MLX_KEY_LEFT && kd.modifier == 0)
		turn_ccw(kd, game);
	if (kd.key == MLX_KEY_RIGHT && kd.modifier == 0)
		turn_cw(kd, game);
	if ((kd.key == MLX_KEY_UP || kd.key == MLX_KEY_W) && kd.modifier == 0)
		move_forward(kd, game);
	if ((kd.key == MLX_KEY_DOWN || kd.key == MLX_KEY_S) && kd.modifier == 0)
		move_backward(kd, game);
	if (kd.key == MLX_KEY_A && kd.modifier == 0)
		move_left(kd, game);
	if (kd.key == MLX_KEY_D && kd.modifier == 0)
		move_right(kd, game);
	if (kd.key == MLX_KEY_R && kd.modifier == 0)
		reset(kd, game);
	if (kd.key == MLX_KEY_ESCAPE && kd.modifier == 0)
		clear_and_exit(game, EXIT_SUCCESS, "");
	draw_ray_on_holder(game);
	draw_screen(game);
}

void	turn_cw(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key != MLX_KEY_RIGHT || keydata.modifier != 0)
		return ;
	game->player->angle += M_PI / 24;
}

void	turn_ccw(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key != MLX_KEY_LEFT || keydata.modifier != 0)
		return ;
	game->player->angle -= M_PI / 24;
}

void	move_forward(mlx_key_data_t kd, t_game *game)
{
	if ((kd.key != MLX_KEY_UP && kd.key != MLX_KEY_W) || kd.modifier != 0)
		return ;
	player_forward(game);
	if (game->minimap_enabled == true)
	{
		update_minimap_coordinates(game);
		game->minimap->player_icon->instances->x = WIDTH + icon_x(game);
		game->minimap->player_icon->instances->y = icon_y(game);
	}
}

void	move_backward(mlx_key_data_t kd, t_game *game)
{
	if ((kd.key != MLX_KEY_DOWN && kd.key != MLX_KEY_S) || kd.modifier != 0)
		return ;
	player_backward(game);
	if (game->minimap_enabled == true)
	{
		update_minimap_coordinates(game);
		game->minimap->player_icon->instances->x = WIDTH + icon_x(game);
		game->minimap->player_icon->instances->y = icon_y(game);
	}
}
