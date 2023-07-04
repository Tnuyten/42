#include "cub3d.h"

void load_img(to_game *game)
{
	game->img_wall = convert_img(game, WALL);
	game->img_exit = convert_img(game, EXIT);
	game->img_player = convert_img(game, PLAYER);
	game->img_collect = convert_img(game, COLLECT);
	game->img_floor = convert_img(game, FLOOR);
}
void *convert_img(to_game *game, char *path)
{
	game->texture = mlx_load_png(path);
	if (!game->texture)
		exit(0);
	game->img = mlx_texture_to_image(game->mlx, game->texture);
	if (!game->img)
		exit(0);
	return (game->img);
}

// remembering that player needs to move according to keyBoard press commands
void player_position(to_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->img_player, x * PIXELS, y * PIXELS);
	game->position_y = y;
	game->position_x = x;
}

void count_colecttabels(to_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->img_collect, x * PIXELS, y * PIXELS);
	game->collect++;
}


void map_render(to_game *game)
{
	int x;
	int y;

	y = 0;
	load_img(game);
	print_bg(game);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img_wall, x * PIXELS, y * PIXELS);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img_exit, x * PIXELS, y * PIXELS);
			if (game->map[y][x] == 'P')
				player_position(game, x, y);
			if (game->map[y][x] == 'C')
				count_colecttabels(game, x, y);
			x++;
		}
		y++;
	}
}