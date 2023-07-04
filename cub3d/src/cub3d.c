#include "cub3d.h"

void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	leaks(void)
{
	system("leaks cub3d");
}

int	main(int argc, char **argv)
{
	t_game	game;

	atexit(leaks);
	if (argc != 2)
	{
		printf("Usage: ./cub3d [map_name].cub");
		return (1);
	}
	if (parse_map(argv[1], &game.map) == -1)
	{
		printf("%s\n", "Something went wrong during parsing.");
		return (1);
	}
	if (validate(&game.map) == false)
	{
		printf("%s\n", "Map is NOT valid.");
		return 1;
	}
	print_map(game.map.map);

	// init_minimap(&game);

	game.mlx = mlx_init(WIDTH + HEIGHT, HEIGHT, "Cub3d", true);
	if (!game.mlx)
		return 1;
	game.player = ft_calloc(sizeof(t_player), 1);

	set_player_spawn(&game);
	make_minimap(&game);
	game.background = make_background(&game);
	mlx_image_to_window(game.mlx, game.background, 0, 0);
	mlx_image_to_window(game.mlx, game.minimap->minimap, WIDTH, 0);
	mlx_image_to_window(game.mlx, game.minimap->player_icon, (int)game.minimap->px + (int)WIDTH, (int)game.minimap->py);
	
	game.ray_holder = mlx_new_image(game.mlx, game.minimap->minimap->width, game.minimap->minimap->height);
	mlx_image_to_window(game.mlx, game.ray_holder, WIDTH, 0);
	game.screen = mlx_new_image(game.mlx, WIDTH, HEIGHT);

	game.cam = ft_calloc(sizeof(t_cam), 1);
	game.cam->ray_angles = ft_calloc(sizeof(double), WIDTH);
	game.cam->ray_ranges = ft_calloc(sizeof(double), WIDTH);
	game.cam->ray_wall_orient = ft_calloc(sizeof(int), WIDTH);
	game.cam->wall_x = ft_calloc(sizeof(t_uint), WIDTH);
	game.cam->wall_y = ft_calloc(sizeof(t_uint), WIDTH);
	game.cam->fov = M_PI/ 3; //90deg

	int x = 0;
	while(x < WIDTH)
	{
		game.cam->ray_angles[x] = -(game.cam->fov / 2) + (x * (game.cam->fov) / WIDTH);
		x++;
	}
	draw_ray(&game);
	draw_screen(&game);

	mlx_image_to_window(game.mlx, game.screen, 0, 0);

	hooks(&game);
	mlx_loop(game.mlx);
}

t_uint get_color_from_texture(mlx_texture_t *tex, t_uint x, t_uint y)
{
	t_uint color;
	if (x < tex->width && y < tex->height)
	{
		color = (*(t_uint*)(tex->pixels + (sizeof(int) * tex->width * y) + (sizeof(int) * x)));
		color = ntohl(color);
		return color;
	}
	return (0x0);
}

t_uint	*get_column_from_texture(t_game* game, t_uint screen_x, t_uint wall_height)
{
	mlx_texture_t	*tex;
	t_uint			orient;
	t_uint			column_to_get;

	orient = game->cam->ray_wall_orient[screen_x];

	if (orient == 1 || orient == 3)
		column_to_get = game->cam->wall_x[screen_x] % game->minimap->tile_width;
	else
		column_to_get = game->cam->wall_y[screen_x] % game->minimap->tile_height;

	if(orient == 0)
		tex = game->map.north;
	if (orient == 1)
		tex = game->map.east;
	if (orient == 2)
		tex = game->map.south;
	if (orient == 3)
		tex = game->map.west;

	t_uint*	col;
	double	scale_factor_x;
	double	scale_factor_y;
	t_uint	tex_x;

	scale_factor_x = tex->width / (double)game->minimap->tile_width;
	scale_factor_y = tex->height / (double)wall_height;
	tex_x = column_to_get * scale_factor_x;
	col = ft_calloc(sizeof(t_uint), wall_height);

	t_uint j = 0;
	while (j < wall_height)
	{
		t_uint tex_y = j * scale_factor_y;
		
		col[j] = get_color_from_texture(tex, tex_x, tex_y);
		j++;
	}
	return col;
}
