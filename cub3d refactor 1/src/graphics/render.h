/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:18:52 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/19 18:42:50 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../cub3d.h"

void		draw_screen(t_game *game);
void		get_column(t_game *game, size_t x, uint32_t *col, size_t offset);
void		set_wall_orient(t_game *game, size_t sx, int i);
uint32_t	get_color_from_texture(mlx_texture_t *tex, size_t x, size_t y);
void		set_ray_range(t_game *game, size_t screen_x, float rx, float ry);

#endif
