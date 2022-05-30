/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:22:58 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/27 16:03:50 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://clintbellanger.net/articles/isometric_math/     !!!

#ifndef FDF_H
# define FDF_H

# include "lib/mlx/mlx.h"
# include "stdlib.h"
# include "lib/gnl/get_next_line.h"
# include "fcntl.h"
# include "lib/libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1200
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define RG 0x00FFFF00
# define RB 0x00FF00FF
# define GB 0x0000FFFF
# define WHITE 0x00FFFFFF

typedef struct	s_mlx_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_image;

typedef struct s_map
{
	int	*map;
	int	width;
	int	height;
	int tile_width;
	int tile_length;
	int tile_height;
	int tile_width_half;
	int tile_length_half;
	int iso_x_origin;
	int iso_y_origin;
	int map_screen_height;
	int map_screen_width;
	float steepness;
}	t_map;

typedef struct s_mlx {
	void		*mlx;
	void		*win;
	t_map		*map;
	t_mlx_image	img;
}	t_mlx;

typedef struct s_coord {
	int x;
	int y;
}	t_coord;

int		close_window_keypress(int keycode, t_mlx *mlx);
int		close_window_button(t_mlx *mlx);
void	image_pixel_put(t_mlx_image img, int x, int y, int color);
t_mlx	*init_mlx();
int		max(int a, int b);
int		min(int a, int b);

#endif