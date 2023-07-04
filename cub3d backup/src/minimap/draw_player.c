#include "minimap.h"

// https://www.geeksforgeeks.org/draw-circle-without-floating-point-arithmetic/
void	draw_player(t_game *game)
{
	int	r;
	int	x;
	int	y;
	int	i;
	int	j;

	r = 6;
	i = 0;
	while (i < 2 * r + 1)
	{
		j = 0;
		while (j < 2 * r + 1)
		{
			x = i - r;
			y = j - r;
			if (x * x + y * y <= r * r + 1)
				mlx_put_pixel(game->minimap->player_icon, x + r, y + r,
					game->minimap->player_color);
			j++;
		}
		i++;
	}	
}

void	put_player_on_minimap(t_game *game)
{
	t_mini		*mini;
	t_player	*player;

	mini = game->minimap;
	player = game->player;
	mini->px = (player->map_x * mini->tile_width) + player->tile_x;
	mini->py = (player->map_y * mini->tile_height) + player->tile_y;
}
