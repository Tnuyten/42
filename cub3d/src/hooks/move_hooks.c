#include "hooks.h"

//	These functions use minimap tile height while 
//	we do not have actual tiles implemented.

void	movement_hooks(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == 0) //keyup
		return ;
	if (keydata.key == MLX_KEY_LEFT && keydata.modifier == 0)
		turn_ccw(keydata, param);
	if (keydata.key == MLX_KEY_RIGHT && keydata.modifier == 0)
		turn_cw(keydata, param);
	if (keydata.key == MLX_KEY_UP && keydata.modifier == 0)
		move_forward(keydata, param);
	if (keydata.key == MLX_KEY_DOWN && keydata.modifier == 0)
		move_backward(keydata, param);
	if (keydata.key == MLX_KEY_R && keydata.modifier == 0)
		reset(keydata, param);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.modifier == 0)
		exit(EXIT_SUCCESS);
	draw_ray(param);
	draw_screen(param);
}

void	turn_cw(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	if (keydata.key != MLX_KEY_RIGHT || keydata.modifier != 0)
		return ;
	game = (t_game *)param;
	game->player->angle +=M_PI/ 24;
}

void	turn_ccw(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	if (keydata.key != MLX_KEY_LEFT || keydata.modifier != 0)
		return ;
	game = (t_game *)param;
	game->player->angle -=M_PI/ 24;
}

void	move_forward(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	if (keydata.key != MLX_KEY_UP || keydata.modifier != 0)
		return ;
	game = (t_game *)param;
	player_forward(game, 5);
	game->minimap->player_icon->instances->x = WIDTH + game->player->map_x * game->minimap->tile_width + game->player->tile_x; //Set new player coordinates to player icon.
	game->minimap->player_icon->instances->y = game->player->map_y * game->minimap->tile_height + game->player->tile_y;
}

void	move_backward(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	if (keydata.key != MLX_KEY_DOWN || keydata.modifier != 0)
		return ;
	game = (t_game *)param;
	player_backward(game, 5);
	game->minimap->player_icon->instances->x = WIDTH + game->player->map_x * game->minimap->tile_width + game->player->tile_x;
	game->minimap->player_icon->instances->y = game->player->map_y * game->minimap->tile_height + game->player->tile_y;
}

void reset(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	if (keydata.key != MLX_KEY_R || keydata.modifier != 0)
		return ;
	game = (t_game *)param;

	set_player_spawn(game);
	game->player->tile_x = game->minimap->tile_width / 2 - game->minimap->player_icon->width / 2;
	game->player->tile_y = game->minimap->tile_height / 2 - game->minimap->player_icon->height / 2;

	game->minimap->player_icon->instances->x = WIDTH + game->player->map_x * game->minimap->tile_width + game->player->tile_x;
	game->minimap->player_icon->instances->y = game->player->map_y * game->minimap->tile_height + game->player->tile_y;
}

// void	move_left(mlx_key_data_t keydata, void *param)
// {
// 	t_game		*game;
// 	t_player	*player;

// 	if (keydata.key != MLX_KEY_LEFT || keydata.modifier != 0)
// 		return ;
// 	game = (t_game *)param;
// 	player = game->player;
// 	if (player->tile_x > 0)
// 		player->tile_x -= 1;
// 	else
// 	{
// 		player->map_x -= 1;
// 		player->tile_x += game->minimap->tile_width - 1;
// 	}
// 	game->minimap->player_icon->instances->x -= 1;
	
// 	printf("[%d,%d]\n", player->map_x, player->map_y);
// }

// void	move_right(mlx_key_data_t keydata, void *param)
// {
// 	t_game		*game;
// 	t_player	*player;

// 	if (keydata.key != MLX_KEY_RIGHT || keydata.modifier != 0)
// 		return ;
// 	game = (t_game *)param;
// 	player = game->player;
// 	if (player->tile_x < game->minimap->tile_width)
// 		player->tile_x += 1;
// 	else
// 	{
// 		player->map_x += 1;
// 		player->tile_x = 1;
// 	}
// 	game->minimap->player_icon->instances->x += 1;
// 	printf("[%d,%d]\n", player->map_x, player->map_y);
// }

// void	move_up(mlx_key_data_t keydata, void *param)
// {
// 	t_game		*game;
// 	t_player	*player = game->player;
// 	if (keydata.key != MLX_KEY_UP || keydata.modifier != 0)
// 		return ;
// 	game = (t_game *)param;
// 	if (player->tile_y > 0)
// 		player->tile_y -= 1;
// 	else
// 	{
// 		player->map_y -= 1;
// 		player->tile_y += game->minimap->tile_height - 1;
// 	}
// 	game->minimap->player_icon->instances->y -= 1;
// 	//game->minimap->player_icon->instances->x -= 1;

// 	printf("[%d,%d]\n", game->player->map_x, game->player->map_y);
// }

// void	move_down(mlx_key_data_t keydata, void *param)
// {
// 	t_game		*game;
// 	t_player	*player;

// 	if (keydata.key != MLX_KEY_DOWN || keydata.modifier != 0)
// 		return ;
// 	game = (t_game *)param;
// 	player = game->player;
// 	if (player->tile_y < game->minimap->tile_height)
// 		player->tile_y += 1;
// 	else
// 	{
// 		player->map_y += 1;
// 		player->tile_y = 1;
// 	}
// 	game->minimap->player_icon->instances->y += 1;
// 	printf("[%d,%d]\n", player->map_x, player->map_y);
// }
