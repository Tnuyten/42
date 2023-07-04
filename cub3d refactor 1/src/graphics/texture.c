/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:18:54 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/19 18:47:40 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static mlx_texture_t	*get_tex_from_orient(t_game *game, size_t screen_x)
{
	size_t	orient;

	orient = game->cam->rays[screen_x]->ray_wall_orient;
	if (orient == 0)
		return (game->map->north);
	if (orient == 1)
		return (game->map->east);
	if (orient == 2)
		return (game->map->south);
	if (orient == 3)
		return (game->map->west);
	return (NULL);
}

static size_t	ctg_from_orient(t_game *game, size_t screen_x)
{
	size_t	orient;
	size_t	column_to_get;
	size_t	us;
	t_ray	*ray;

	ray = game->cam->rays[screen_x];
	us = game->unit_size;
	orient = ray->ray_wall_orient;
	if (orient == 0)
		column_to_get = ray->wall_x % us;
	else if (orient == 2)
		column_to_get = us - ray->wall_x % us;
	else if (orient == 1)
		column_to_get = ray->wall_y % us;
	else
		column_to_get = us - ray->wall_y % us;
	return (column_to_get);
}

void	get_column(t_game *game, size_t x, uint32_t *col, size_t offset)
{
	mlx_texture_t	*tex;
	float			scale_y;
	size_t			tex_x;
	size_t			tex_y;
	size_t			j;

	offset = (game->cam->rays[x]->full_height - HEIGHT) / 2;
	tex = get_tex_from_orient(game, x);
	if (tex == NULL)
		return ;
	scale_y = tex->height / (float)game->cam->rays[x]->full_height;
	tex_x = ctg_from_orient(game, x) * (tex->width / (float)game->unit_size);
	if (tex_x != 0)
		tex_x--;
	j = 0;
	while (j < game->cam->rays[x]->screen_height)
	{
		if (game->cam->rays[x]->full_height > HEIGHT)
			tex_y = (j + offset) * scale_y;
		else
			tex_y = j * scale_y;
		col[j] = get_color_from_texture(tex, tex_x, tex_y);
		j++;
	}
}

// void	set_wall_orientation(t_game *game, size_t screen_x)
// {
// 	float	dx;
// 	float	dy;
// 	size_t	ray_x;
// 	size_t	ray_y;

// 	dx = game->cam->rays[screen_x]->dx;
// 	dy = game->cam->rays[screen_x]->dy;
// 	ray_x = game->cam->rays[screen_x]->wall_x;
// 	ray_y = game->cam->rays[screen_x]->wall_y;
// 	if (dx > 0 && ray_x % game->unit_size == 0)
// 		game->cam->rays[screen_x]->ray_wall_orient = 1;
// 	else if (dy > 0 && ray_y % game->unit_size == 0)
// 		game->cam->rays[screen_x]->ray_wall_orient = 2;
// 	else if (dx < 0 && (1 + ray_x) % game->unit_size == 0)
// 		game->cam->rays[screen_x]->ray_wall_orient = 3;
// 	else if (dy < 0 && (1 + ray_y) % game->unit_size == 0)
// 		game->cam->rays[screen_x]->ray_wall_orient = 0;
// 	else
// 		game->cam->rays[screen_x]->ray_wall_orient = -1;
// }

void	set_wall_orient(t_game *game, size_t screen_x, int i)
{
	t_ray	*ray;

	ray = game->cam->rays[screen_x];
	ray->prev_mx = ray->mx;
	ray->prev_my = ray->my;
	if (i % 2 == 0)
		ray->prev_my = floor((ray->ry - ray->dy) / game->unit_size);
	else
		ray->prev_mx = floor((ray->rx - ray->dx) / game->unit_size);
	if (ray->prev_mx > ray->mx && ray->prev_my == ray->my)
		game->cam->rays[screen_x]->ray_wall_orient = 3;
	else if (ray->prev_mx < ray->mx && ray->prev_my == ray->my)
		game->cam->rays[screen_x]->ray_wall_orient = 1;
	else if (ray->prev_mx == ray->mx && ray->prev_my > ray->my)
		game->cam->rays[screen_x]->ray_wall_orient = 0;
	else if (ray->prev_mx == ray->mx && ray->prev_my < ray->my)
		game->cam->rays[screen_x]->ray_wall_orient = 2;
}

uint32_t	get_color_from_texture(mlx_texture_t *tex, size_t x, size_t y)
{
	uint8_t	*pptr;
	size_t	val;

	if (x >= tex->width)
		return (0);
	if (y >= tex->height)
		return (0);
	val = x + tex->width * y;
	pptr = &tex->pixels[val * tex->bytes_per_pixel];
	return ((pptr[0] << 24 | pptr[1] << 16 | pptr[2] << 8 | pptr[3] << 0));
}
