#include "minimap.h"

static void	prepare(t_game *game);

void init_minimap(t_game *game)
{
	prepare(game);
}

static void	prepare(t_game *game)
{
	t_mini	*minimap;
	t_map	map;

	minimap = game->minimap;
	map = game->map;
	clear_image(minimap->minimap, 0x000000FF);
	minimap->wall_color = 0xC19A6BFF;
	minimap->border_color = 0xFFFFFFFF;
	minimap->floor_color = 0x008000FF;
	minimap->spawn_color = 0xFFFF00FF;
	minimap->player_color = 0xF0000080;
	minimap->tile_width = minimap->minimap->width / map.width;
	minimap->tile_height = minimap->minimap->height / map.height;
	if (map.width <= map.height)
	{
		minimap->tile_height = minimap->minimap->height / map.height;
		minimap->tile_width = minimap->tile_height;
	}
	else
	{
		minimap->tile_width = minimap->minimap->width / map.width;
		minimap->tile_height = minimap->tile_width;
	}
	minimap->h_margin = (minimap->minimap->height % map.height) / 2;
	minimap->w_margin = (minimap->minimap->width % map.width) / 2;
	if(map.width > map.height)
	{
		minimap->h_offset = (minimap->minimap->height - map.height * minimap->tile_height) / 2;
		minimap->w_offset = 0;
	}
	else
	{
		minimap->h_offset = 0;
		minimap->w_offset = (minimap->minimap->width - map.width * minimap->tile_width) / 2;
	}
	minimap->player_icon = mlx_new_image(game->mlx, 13, 13);
	game->player->tile_x = game->minimap->tile_width / 2 - 6;
	game->player->tile_y = game->minimap->tile_height / 2 - 6;
	draw_player(game);
}