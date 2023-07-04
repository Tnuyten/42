#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_color	t_color;
typedef struct s_map	t_map;
typedef struct s_player	t_player;
typedef struct s_cam	t_cam;
typedef struct s_game	t_game;
typedef struct s_coord	t_coord;
typedef struct s_mini	t_mini;
typedef struct s_ray	t_ray;
typedef unsigned int	t_uint;

struct	s_color
{
	int	red;
	int	green;
	int	blue;
};

struct	s_map {
	t_uint			height;
	t_uint			width;
	char			**map;
	char			path_to_map;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	t_uint			floor_color;
	t_uint			ceil_color;
};

struct	s_player {
	double		angle;
	t_uint		map_x;
	t_uint		map_y;
	double		tile_x;
	double		tile_y;
};

struct	s_cam {
	t_uint		width;
	t_uint		height;
	double		fov;
	double		*ray_angles;
	double		*ray_ranges;
	int			*ray_wall_orient;
	t_uint		*wall_x;
	t_uint		*wall_y;
	double		tanfov;
};

struct	s_game {
	t_map		map;
	mlx_t		*mlx;
	t_cam		*cam;
	t_player	*player;
	t_mini		*minimap;
	mlx_image_t	*background;
	mlx_image_t	*ray_holder;
	mlx_image_t	*screen;
};

struct s_coord {
	t_uint	x;
	t_uint	y;
};

struct s_mini {
	mlx_image_t		*minimap;
	t_uint			tile_width;
	t_uint			tile_height;
	t_uint			wall_color;
	t_uint			border_color;
	t_uint			floor_color;
	t_uint			spawn_color;
	t_uint			h_margin;
	t_uint			w_margin;
	t_uint			h_offset;
	t_uint			w_offset;
	mlx_image_t		*player_icon;
	t_uint			player_color;
	t_uint			px;
	t_uint			py;
};

struct s_ray {
	t_uint	end_x;
	t_uint	end_y;
};

#endif
