/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:38 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/19 18:38:53 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	free_rays(t_ray **rays)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		if (rays[x] != NULL)
			free(rays[x]);
		x++;
	}
	free(rays);
}

void	free_cam(t_cam *cam)
{
	if (cam->rays != NULL)
		free_rays(cam->rays);
	if (cam->col != NULL)
		free(cam->col);
	free(cam);
}

void	free_map(t_map *map)
{
	size_t	i;

	if (map == NULL)
		return ;
	i = -1;
	if (map->map != NULL)
	{
		while (++i < map->height)
		{
			if (map->map[i] != NULL)
				free(map->map[i]);
		}
		free(map->map);
	}
	if (map->row_lens != NULL)
		free(map->row_lens);
	if (map->north)
		mlx_delete_texture(map->north);
	if (map->east)
		mlx_delete_texture(map->east);
	if (map->south)
		mlx_delete_texture(map->south);
	if (map->west)
		mlx_delete_texture(map->west);
	free(map);
}

void	clear_and_exit(t_game *game, int exit_status, char *message)
{
	if (exit_status == EXIT_FAILURE)
		printf("Error\n");
	printf("%s\n", message);
	if (game->player)
		free(game->player);
	if (game->minimap)
		free(game->minimap);
	if (game->cam)
		free_cam(game->cam);
	if (game->map)
		free_map(game->map);
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(exit_status);
}
