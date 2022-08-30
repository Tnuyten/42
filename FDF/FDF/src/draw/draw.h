/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:35:44 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/30 20:16:29 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../../fdf.h"
# include "../line/line.h"
# include "../iso/iso.h"

void	redraw(t_mlx *mlx);
void	draw_map(t_mlx mlx, int m, int n, int direction);
void	clear_image(t_mlx mlx);
void	image_pixel_put(t_mlx_image img, int x, int y, int color);

#endif