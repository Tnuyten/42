#include "minimap.h"

static void	prepare(t_game *game);
static int	x_is_edge(t_mini *minimap, t_uint xx, t_uint x_start);
static int	y_is_edge(t_mini *minimap, t_uint yy, t_uint y_start);

void	place_tile(t_mini *mini, t_uint x, t_uint y, t_map map)
{
	t_uint	yy;
	t_uint	xx;
	t_uint	x_start;
	t_uint	y_start;

	x_start = x * mini->tile_width;
	y_start = y * mini->tile_height;
	yy = y_start;
	while (yy < y_start + mini->tile_height && yy < mini->minimap->height)
	{
		xx = x_start;
		while (xx < x_start + mini->tile_width && xx < mini->minimap->width)
		{
			if (map.map[y][x] == '1')
				mlx_put_pixel(mini->minimap, xx, yy, mini->wall_color);
			else if (map.map[y][x] == '0' || map.map[y][x] == '8')
				mlx_put_pixel(mini->minimap, xx, yy, mini->floor_color);
			else if (is_player_spawn(map.map[y][x]))
				mlx_put_pixel(mini->minimap, xx, yy, mini->spawn_color);
			if (x_is_edge(mini, xx, x_start) || y_is_edge(mini, yy, y_start))
				mlx_put_pixel(mini->minimap, xx, yy, mini->border_color);
			xx++;
		}
		yy++;
	}
}

void	make_minimap(t_game *game)
{
	t_mini	*mini;
	t_uint	x;
	t_uint	y;

	mini = (t_mini *)ft_calloc(1, sizeof(t_mini));
	if (mini == NULL)
		return ;
	game->minimap = mini;
	mini->minimap = mlx_new_image(game->mlx, HEIGHT, HEIGHT);
	prepare(game);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < ft_strlen(game->map.map[y]))
		{
			place_tile(mini, x, y, game->map);
			//Add center dots
			t_uint x_mid = x * game->minimap->tile_width + game->minimap->tile_width / 2;
			t_uint y_mid = y * game->minimap->tile_height + game->minimap->tile_height / 2;
			mlx_put_pixel(game->minimap->minimap, x_mid - 1, y_mid - 1, 0x000000FF);
			mlx_put_pixel(game->minimap->minimap, x_mid - 1, y_mid, 0x000000FF);
			mlx_put_pixel(game->minimap->minimap, x_mid, y_mid - 1, 0x000000FF);
			mlx_put_pixel(game->minimap->minimap, x_mid, y_mid, 0xFFFFFFFF);
			mlx_put_pixel(game->minimap->minimap, x_mid + 1, y_mid, 0x000000FF);
			mlx_put_pixel(game->minimap->minimap, x_mid, y_mid + 1, 0x000000FF);
			mlx_put_pixel(game->minimap->minimap, x_mid + 1, y_mid + 1, 0x000000FF);
			mlx_put_pixel(game->minimap->minimap, x_mid - 1, y_mid + 1, 0x000000FF);
			mlx_put_pixel(game->minimap->minimap, x_mid + 1, y_mid - 1, 0x000000FF);
			x++;
		}
		y++;
	}
	put_player_on_minimap(game);
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

static int	x_is_edge(t_mini *minimap, t_uint xx, t_uint x_start)
{
	if (xx == x_start || xx == x_start + minimap->tile_width - 1)
		return (1);
	return (0);
}

static int	y_is_edge(t_mini *minimap, t_uint yy, t_uint y_start)
{
	if (yy == y_start || yy == y_start + minimap->tile_height - 1)
		return (1);
	return (0);
}
