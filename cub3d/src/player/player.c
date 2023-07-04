#include "player.h"

// Set player starting position and orientation. Don't forget, east is 0 degrees.
void set_player_spawn(t_game *game)
{
	t_uint	y = 0;
	t_uint	x = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < ft_strlen(game->map.map[y]))
		{
			if (is_player_spawn(game->map.map[y][x]))
			{
				game->player->map_x = x;
				game->player->map_y = y;
				if(game->map.map[y][x] == 'N')
					game->player->angle =M_PI+M_PI/ 2;
				if(game->map.map[y][x] == 'E')
					game->player->angle = 2 * M_PI;
				if(game->map.map[y][x] == 'S')
					game->player->angle =M_PI/ 2;
				if(game->map.map[y][x] == 'W')
					game->player->angle = M_PI;
			}
			x++;
		}
		y++;
	}
}