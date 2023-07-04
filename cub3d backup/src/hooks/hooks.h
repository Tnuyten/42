#ifndef HOOKS_H
# define HOOKS_H

# include "../cub3d.h"
# include "../player/player.h"

// General hook wrapper function. 
void	hooks(t_game *game);

// Player movement hooks.
void	movement_hooks(mlx_key_data_t keydata, void *param);
void	move_forward(mlx_key_data_t keydata, void *param);
void	move_backward(mlx_key_data_t keydata, void *param);
void	turn_cw(mlx_key_data_t keydata, void *param);
void	turn_ccw(mlx_key_data_t keydata, void *param);
void	reset(mlx_key_data_t keydata, void *param);


// old way of moving
// void	move_left(mlx_key_data_t keydata, void *param);
// void	move_right(mlx_key_data_t keydata, void *param);
// void	move_up(mlx_key_data_t keydata, void *param);
// void	move_down(mlx_key_data_t keydata, void *param);

#endif
