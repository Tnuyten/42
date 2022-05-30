/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:28:03 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/30 13:58:41 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "../../fdf.h"

void draw_horizontal_line(t_mlx_image img, t_coord start, t_coord end, int color);
void draw_vertical_line(t_mlx_image img, t_coord start, t_coord end, int color);
// void image_draw_small_m_line(t_mlx_image img, t_coord start, t_coord end, int color);
// void image_draw_big_m_line(t_mlx_image img, t_coord start, t_coord end, int color);
void image_draw_line(t_mlx mlx, t_coord start, t_coord end, int color);
void image_draw_line_bresenham(t_mlx_image img, t_coord start, t_coord end, int color);

#endif