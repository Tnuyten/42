/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:22:58 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/19 19:51:05 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// https://clintbellanger.net/articles/isometric_math/     !!!

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "stdlib.h"
# include "gnl/get_next_line.h"
# include "fcntl.h"
# include "libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1200

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_data	img;
} t_mlx;

typedef struct s_coord {
	int x;
	int y;
} t_coord;

typedef struct s_map
{
	int	*map;
	int	width;
	int	height;
} t_map;

int		close_window_keypress(int keycode, t_mlx *mlx);
int		close_window_button(t_mlx *mlx);
void	image_pixel_put(t_data img, int x, int y, int color);
t_mlx	*init_mlx();

#endif