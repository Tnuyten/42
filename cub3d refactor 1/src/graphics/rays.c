/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:54:15 by dkocob            #+#    #+#             */
/*   Updated: 2023/04/20 17:48:22 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	put_screen(t_game *g, size_t x, int offset, uint32_t *col2p)
{
	size_t	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y + offset < HEIGHT)
			mlx_put_pixel(g->screen, x, y + offset, col2p[y]);
		else
		{
			mlx_put_pixel(g->screen, x, y - 1, g->map->floor_color);
			mlx_put_pixel(g->screen, x, HEIGHT - 1 - y, g->map->ceil_color);
		}
		y++;
	}
}

void	set_ray_range(t_game *game, size_t screen_x, float rx, float ry)
{
	float	length;
	float	range;

	length = sqrt(pow(rx - game->player->x, 2) + pow(ry - game->player->y, 2));
	range = length * cos(game->cam->rays[screen_x]->ray_angle);
	game->cam->rays[screen_x]->ray_range = range;
	game->cam->rays[screen_x]->wall_x = floor(rx);
	game->cam->rays[screen_x]->wall_y = floor(ry);
}

static void	ray_loop(t_game *g, size_t screen_x)
{
	int			i;
	t_ray		*ray;

	ray = g->cam->rays[screen_x];
	i = 0;
	ray->rx = g->player->x;
	ray->ry = g->player->y;
	while (1)
	{
		ray->my = floor(ray->ry / g->unit_size);
		ray->mx = floor(ray->rx / g->unit_size);
		if (ray->my >= g->map->height || ray->mx >= g->map->row_lens[ray->my])
			break ;
		if (ray->my < g->map->height && ray->mx < g->map->row_lens[ray->my]
			&& g->map->map[ray->my][ray->mx] == '1')
		{
			set_ray_range(g, screen_x, ray->rx, ray->ry);
			set_wall_orient(g, screen_x, i);
			break ;
		}
		ray->rx += ray->dx * (i % 2 == 0);
		ray->ry += ray->dy * (i++ % 2 == 1);
	}
}

static void	ray_length(t_game *game, size_t screen_x)
{
	float		ray_angle;
	float		dx;
	float		dy;

	ray_angle = game->cam->rays[screen_x]->ray_angle + game->player->angle;
	game->cam->rays[screen_x]->dx = cos(ray_angle);
	game->cam->rays[screen_x]->dy = sin(ray_angle);
	game->cam->rays[screen_x]->ray_range = 0;
	game->cam->rays[screen_x]->ray_wall_orient = 0;
	game->cam->rays[screen_x]->wall_x = 0;
	game->cam->rays[screen_x]->wall_y = 0;
	dx = game->cam->rays[screen_x]->dx;
	dy = game->cam->rays[screen_x]->dy;
	ray_loop(game, screen_x);
}

void	draw_screen(t_game *game)
{
	size_t		x;
	int			offset;
	t_ray		*ray;
	uint32_t	*col2p;
	size_t		wall_height;

	col2p = game->cam->col;
	x = 0;
	while (x < WIDTH)
	{
		ray = game->cam->rays[x];
		ray_length(game, x);
		wall_height = game->unit_size;
		wall_height *= HEIGHT * 1.7 / (ray->ray_range * game->cam->tanfov);
		ray->full_height = wall_height;
		ray->screen_height = min(HEIGHT, ray->full_height);
		offset = (HEIGHT - ray->screen_height) / 2;
		ft_bzero(col2p, HEIGHT * sizeof(size_t));
		get_column(game, x, col2p, offset);
		put_screen(game, x, offset, col2p);
		x++;
	}
}
