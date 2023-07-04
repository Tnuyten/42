/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:59 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:20:00 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "../cub3d.h"

// init.c
void	init_minimap(t_game *game);
void	allocate_minimap(t_game *game);

// minimap.c
void	make_minimap(t_game *game);

// draw_ray.c
void	draw_line(t_game *game, float dx, float dy, size_t color);
void	draw_ray_on_holder(t_game *game);

// player_icon.c
void	draw_icon(t_game *game);
void	update_minimap_coordinates(t_game *game);
size_t	icon_x(t_game *game);
size_t	icon_y(t_game *game);

#endif
