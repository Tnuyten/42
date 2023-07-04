/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:44 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/19 18:42:08 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"
# include <stddef.h>

typedef struct s_map	t_map;
typedef struct s_player	t_player;
typedef struct s_cam	t_cam;
typedef struct s_game	t_game;
typedef struct s_coord	t_coord;
typedef struct s_mini	t_mini;
typedef struct s_ray	t_ray;

struct	s_map {
	size_t			height;
	size_t			width;
	char			**map;
	size_t			*row_lens;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	uint32_t		floor_color;
	uint32_t		ceil_color;
};

struct	s_game {
	t_map		*map;
	mlx_t		*mlx;
	t_cam		*cam;
	t_player	*player;
	t_mini		*minimap;
	mlx_image_t	*screen;
	size_t		unit_size;
	int			minimap_enabled;
};

struct	s_player {
	float		angle;
	float		x;
	float		y;
	float		move_speed;
};

struct	s_cam {
	size_t		width;
	size_t		height;
	float		fov;
	float		tanfov;
	t_ray		**rays;
	uint32_t	*col;
};

struct s_mini {
	mlx_image_t		*minimap;
	size_t			tile_size;
	uint32_t		wall_color;
	uint32_t		border_color;
	uint32_t		floor_color;
	uint32_t		spawn_color;
	mlx_image_t		*player_icon;
	mlx_image_t		*ray_holder;
	size_t			player_color;
	size_t			mini_x;
	size_t			mini_y;
	float			map_scale_factor;
};

struct s_ray {
	float	ray_angle;
	float	ray_range;
	float	ray_wall_orient;
	size_t	wall_x;
	size_t	wall_y;
	float	dx;
	float	dy;
	size_t	screen_height;
	size_t	full_height;
	size_t	mx;
	size_t	my;
	size_t	prev_mx;
	size_t	prev_my;
	float	rx;
	float	ry;
};

#endif
