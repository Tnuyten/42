/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_icon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:03 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:20:04 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

// https://www.geeksforgeeks.org/draw-circle-without-floating-point-arithmetic/
void	draw_icon(t_game *game)
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

void	update_minimap_coordinates(t_game *game)
{
	t_mini		*mini;
	t_player	*player;

	mini = game->minimap;
	player = game->player;
	mini->mini_x = player->x * mini->map_scale_factor;
	mini->mini_y = player->y * mini->map_scale_factor;
}

size_t	icon_x(t_game *game)
{
	return (game->minimap->mini_x - game->minimap->player_icon->width / 2);
}

size_t	icon_y(t_game *game)
{
	return (game->minimap->mini_y - game->minimap->player_icon->height / 2);
}
