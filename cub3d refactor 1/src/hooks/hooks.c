/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:06 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:19:07 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	exit_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	clear_and_exit(game, EXIT_SUCCESS, "");
}

void	hooks(t_game *game)
{
	mlx_key_hook(game->mlx, movement_hooks, game);
	mlx_close_hook(game->mlx, exit_hook, game);
}
