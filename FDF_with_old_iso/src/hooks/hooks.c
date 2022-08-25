/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:53:05 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/25 17:28:26 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

// 53 == ESC, 7 == x, 6 == z, 0 == a, 2 == d, 1 == s, 13 == w
int	keyhooks(int keycode, t_mlx *mlx)
{
	if (keycode == 0 || (0 && keycode == 'a'))
		mlx->map->x_offset -= WIDTH / 20;
	else if (keycode == 2 || (0 && keycode == 'd'))
		mlx->map->x_offset += WIDTH / 20;
	else if (keycode == 1 || (0 && keycode == 's'))
		mlx->map->y_offset += HEIGHT / 20;
	else if (keycode == 13 || (0 && keycode == 'w'))
		mlx->map->y_offset -= HEIGHT / 20;
	else if (keycode == 7 || (0 && keycode == 'x'))
		mlx->map->steepness += 0.1;
	else if (keycode == 6 || (0 && keycode == 'z'))
		mlx->map->steepness -= 0.1;
	else if (keycode == 35 || (0 && keycode == 'p'))
		mlx->map->angle += 10;
	else if (keycode == 37 || (0 && keycode == 'l'))
		mlx->map->angle -= 10;
	else if (keycode == 53 || (0 && keycode == '\0'))
	{
		free_all(mlx);
		exit(EXIT_SUCCESS);
	}
	else
		return (0);
	redraw(mlx);
	return (0);
}

int	close_window_button(t_mlx *mlx)
{
	free_all(mlx);
	exit(EXIT_SUCCESS);
}