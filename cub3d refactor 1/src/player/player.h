/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:23 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:20:24 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../cub3d.h"

// player_move.c
void	player_forward(t_game *game);
void	player_backward(t_game *game);
void	player_left(t_game *game);
void	player_right(t_game *game);
void	player_move(t_game *game, float dx, float dy);

// player.c
void	find_player_spawn(t_game *game);

#endif
