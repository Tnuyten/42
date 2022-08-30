/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:25:26 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/30 21:25:26 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_mlx_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_image;

typedef struct s_map
{
	int		*map;
	int		*color_map;
	int		width;
	int		height;
	int		tile_height;
	int		x_offset;
	int		y_offset;
	int		angle;
	float	steepness;
}	t_map;

typedef struct s_mlx {
	t_map		*map;
	t_mlx_image	img;
	int			img_active;
	void		*mlx;
	void		*win;
}	t_mlx;

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

#endif