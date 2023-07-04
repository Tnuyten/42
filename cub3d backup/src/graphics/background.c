#include "../cub3d.h"

mlx_image_t	*make_background(t_game *game)
{
	mlx_image_t	*background;
	int			y;
	int			x;
	int			middle;

	middle = HEIGHT / 2;
	y = 0;
	background = mlx_new_image(game->mlx, WIDTH, HEIGHT);

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y <= middle)
				mlx_put_pixel(background, x, y, game->map.ceil_color);
			else
				mlx_put_pixel(background, x, y, game->map.floor_color);
			x++;
		}
		y++;
	}
	return (background);
}
