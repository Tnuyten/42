/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:08 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:19:09 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "../cub3d.h"
# include "../player/player.h"

// General hook wrapper function. 
void	hooks(t_game *game);

// Player movement hooks.
void	movement_hooks(mlx_key_data_t keydata, void *param);
void	move_forward(mlx_key_data_t keydata, t_game *game);
void	move_backward(mlx_key_data_t keydata, t_game *game);
void	turn_cw(mlx_key_data_t keydata, t_game *game);
void	turn_ccw(mlx_key_data_t keydata, t_game *game);
void	reset(mlx_key_data_t keydata, t_game *game);
void	move_left(mlx_key_data_t keydata, t_game *game);
void	move_right(mlx_key_data_t keydata, t_game *game);

#endif
