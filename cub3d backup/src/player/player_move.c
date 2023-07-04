#include "player.h"

void player_forward(t_game *game, int speed)
{
	double dx = cos(game->player->angle) * speed;//* (1 + (game->cam->ray_lengths[WIDTH / 2] < 4) * -2); //Calculate the change in direction
	double dy = sin(game->player->angle) * speed;//* (1 + (game->cam->ray_lengths[WIDTH / 2] < 4) * -2);

	game->player->tile_x += dx;
	game->player->tile_y += dy;

	if(game->player->tile_x >= (int)game->minimap->tile_width)
	{
		game->player->map_x++;
		game->player->tile_x -= game->minimap->tile_width;
	}
	if(game->player->tile_x < 0)
	{
		game->player->map_x--;
		game->player->tile_x += game->minimap->tile_width;
	}
	if(game->player->tile_y >= (int)game->minimap->tile_height)
	{
		game->player->map_y++;
		game->player->tile_y -= game->minimap->tile_height;
	}
	if(game->player->tile_y < 0)
	{
		game->player->map_y--;
		game->player->tile_y += game->minimap->tile_height;
	}

	if(game->map.map[game->player->map_y][game->player->map_x] == '1' 
		&& ( game->player->tile_x <= 5 ||
			 game->player->tile_y <= 5 ||
			 game->player->tile_x >= game->minimap->tile_width - 5 ||
			 game->player->tile_y >= game->minimap->tile_height - 5 ))
	{
		player_forward(game, -speed);
	}
}

void player_backward(t_game *game, int speed)
{
	player_forward(game, -speed);
}

// TODO: player left, player right
