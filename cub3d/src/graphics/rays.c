#include "../cub3d.h"

void	line_length(t_game *game, t_uint screen_x)
{
	double	y;
	double	x;
	double	dx;
	double	dy;
	t_uint	my;
	t_uint	mx;
	t_player *player = game->player;

	dx = cos(game->cam->ray_angles[screen_x] + player->angle);
	dy = sin(game->cam->ray_angles[screen_x] + player->angle);

	x = player->map_x * game->minimap->tile_width + player->tile_x;
	y = player->map_y * game->minimap->tile_height + player->tile_y;
	x += game->minimap->player_icon->width / 2;
	y += game->minimap->player_icon->height / 2;
	t_uint	ox = (t_uint)x;
	t_uint	oy = (t_uint)y;

	while (1)
	{
		my = y / game->minimap->tile_height;
		mx = x / game->minimap->tile_width;
		if (x >= game->ray_holder->width || x < 0)
			break ;
		if (y >= game->ray_holder->height || y < 0)
			break ;
		if (my < game->map.height && mx < ft_strlen(game->map.map[my]) \
			&& my >= 0 && mx >= 0\
			&& game->map.map[my][mx] == '1')
		{
			t_uint	vx = fabs(x - ox);
			t_uint	vy = fabs(y - oy);
			double	length = sqrt(vx*vx + vy*vy);
			game->cam->ray_ranges[screen_x] = round(length * cos(game->cam->ray_angles[screen_x]));
			game->cam->wall_x[screen_x] = x;
			game->cam->wall_y[screen_x] = y;

			// TODO Fix side detection
			if (dx > 0 && (int)x % game->minimap->tile_width == 0) // look right and intersect vertical wall
				game->cam->ray_wall_orient[screen_x] = 0;
			else if (dy > 0 && (int)y % game->minimap->tile_height == 0)// look down and intersect horizontal wall
				game->cam->ray_wall_orient[screen_x] = 1;
			else if (dx < 0 && (1 + (int)x) % game->minimap->tile_width == 0) //look left and intersect vertical wall
				game->cam->ray_wall_orient[screen_x] = 2;
			else if (dy < 0 && (1 + (int)y) % game->minimap->tile_height == 0) //look up and intersect horizontal wall
				game->cam->ray_wall_orient[screen_x] = 3;
			break ;
		}
		x += dx;
		y += dy;
	}
}

void	draw_line(t_game *game, double angle, t_uint color)
{
	float	y;
	float	x;
	float	dx;
	float	dy;
	t_uint	my;
	t_uint	mx;

	dx = cos(angle);
	dy = sin(angle);
	x = game->player->map_x * game->minimap->tile_width + game->player->tile_x; 
	y = game->player->map_y * game->minimap->tile_height + game->player->tile_y;
	x += game->minimap->player_icon->width / 2;
	y += game->minimap->player_icon->height / 2;
	while (1)
	{
		my = y / game->minimap->tile_height;
		mx = x / game->minimap->tile_width;
		if (x >= game->ray_holder->width || x < 0)
			break;
		if (y >= game->ray_holder->height || y < 0)
			break;
		if (my < game->map.height && mx < ft_strlen(game->map.map[my]) && my >= 0 && mx >= 0\
			&& game->map.map[my][mx] == '1')
			break ;
		mlx_put_pixel(game->ray_holder, x, y, color);
		x += dx;
		y += dy;
	}
}

void draw_ray(t_game *game) {
	t_player *player;
	t_uint x;
	t_uint y;
	t_uint i;
	
	player = game->player;
	clear_image(game->ray_holder, 0x00000000);
	x = player->map_x * game->minimap->tile_width + player->tile_x;
	y = player->map_y * game->minimap->tile_height + player->tile_y;
	x += game->minimap->player_icon->width / 2;
	y += game->minimap->player_icon->height / 2;


	i = 0;
	while (i < WIDTH)
	{
		if (i % 50 == 0 || i == 0 || i == WIDTH / 2 || i == WIDTH - 1)
		{
			if (i == 0 || i == WIDTH / 2 || i == WIDTH - 1)
				draw_line(game, game->cam->ray_angles[i] + player->angle, 0xFF0000FF);
			else
				draw_line(game, game->cam->ray_angles[i] + player->angle, 0xFF00FFFF);
		}
		line_length(game, i);
		i++;
	}
}

t_uint get_wall_height(t_game *game, t_uint screen_x)
{
	double inside = (2 * game->cam->ray_ranges[screen_x] * game->cam->tanfov);
	return round(100 * (HEIGHT / inside));
}

void draw_screen(t_game *game)
{
	t_uint	height;
	t_uint	*col;
	int		offset;
	t_uint	x;
	t_uint	y;

	game->cam->tanfov = tan(game->cam->fov / 2); //should probably be moved to init, after fov is calculated.
	clear_image(game->screen, 0x00000000);
	x = 0;
	while (x < WIDTH)
	{
		height = get_wall_height(game, x);
		col = get_column_from_texture(game, x, height);
		offset = (HEIGHT - (int)height) / 2;
		y = 0;
		while (y < height)
		{
			if (y + offset >= 0 && y + offset < game->screen->height)
				mlx_put_pixel(game->screen, x, y + offset, col[y]);
			y++;
		}
		x++;
	}
}
