#ifndef PLAYER_H
# define PLAYER_H

#include "../cub3d.h"

// player_move.c
void player_forward(t_game *game, int speed);
void player_backward(t_game *game, int speed);

// player.c

void set_player_spawn(t_game *game);

#endif
