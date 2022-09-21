/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:53:05 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/08 17:07:32 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	keyhooks(int keycode, t_mlx *mlx)
{
	if (keycode == 7 || (0 && keycode == 'x'))
		mlx->map->steepness += 0.1f;
	else if (keycode == 6 || (0 && keycode == 'z'))
		mlx->map->steepness -= 0.1f;
	else if (keycode == 35 || (0 && keycode == 'p'))
		mlx->map->angle += 15;
	else if (keycode == 37 || (0 && keycode == 'l'))
		mlx->map->angle -= 15;
	else if (keycode == 45 || (0 && keycode == 'n'))
		mlx->map->scale_factor += 1;
	else if (keycode == 46 || (0 && keycode == 'm'))
		mlx->map->scale_factor -= 1;
	else if (keycode == 53 || (0 && keycode == '\0'))
	{
		free_all(mlx);
		exit(EXIT_SUCCESS);
	}
	else if (more_keyhooks(keycode, mlx) == 0)
		return (0);
	else
		return (0);
	redraw(mlx);
	return (0);
}

int	more_keyhooks(int keycode, t_mlx *mlx)
{
	if (keycode == 0 || (0 && keycode == 'a'))
		mlx->map->x_offset -= WIDTH / 20;
	else if (keycode == 2 || (0 && keycode == 'd'))
		mlx->map->x_offset += WIDTH / 20;
	else if (keycode == 1 || (0 && keycode == 's'))
		mlx->map->y_offset += HEIGHT / 20;
	else if (keycode == 13 || (0 && keycode == 'w'))
		mlx->map->y_offset -= HEIGHT / 20;
	else
		return (1);
	redraw(mlx);
	return (0);
}

int	close_window_button(t_mlx *mlx)
{
	free_all(mlx);
	exit(EXIT_SUCCESS);
}
