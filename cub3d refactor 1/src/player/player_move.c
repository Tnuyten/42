/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:19 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:20:20 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_forward(t_game *game)
{
	float	dx;
	float	dy;

	dx = cos(game->player->angle) * game->player->move_speed;
	dy = sin(game->player->angle) * game->player->move_speed;
	player_move(game, dx, dy);
}

void	player_backward(t_game *game)
{
	float	dx;
	float	dy;

	dx = cos(game->player->angle + M_PI) * game->player->move_speed;
	dy = sin(game->player->angle + M_PI) * game->player->move_speed;
	player_move(game, dx, dy);
}

void	player_left(t_game *game)
{
	float	dx;
	float	dy;

	dx = cos(game->player->angle - M_PI_2) * game->player->move_speed;
	dy = sin(game->player->angle - M_PI_2) * game->player->move_speed;
	player_move(game, dx, dy);
}

void	player_right(t_game *game)
{
	float	dx;
	float	dy;

	dx = cos(game->player->angle + M_PI_2) * game->player->move_speed;
	dy = sin(game->player->angle + M_PI_2) * game->player->move_speed;
	player_move(game, dx, dy);
}

void	player_move(t_game *game, float dx, float dy)
{
	game->player->x += dx;
	game->player->y += dy;
}
