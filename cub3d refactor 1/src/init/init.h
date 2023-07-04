/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:22 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:19:46 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../cub3d.h"

void	init(t_game *game);
void	clear_and_exit(t_game *game, int exit_status, char *message);
void	calculate_cam_angles(t_game *game);

#endif
