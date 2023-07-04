/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:19 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/19 18:38:53 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	set_row_lengths(t_game *game);

static void	allocate_rays(t_game *game)
{
	int	x;

	game->cam->rays = ft_calloc(sizeof(t_ray *), WIDTH);
	if (game->cam->rays == NULL)
		clear_and_exit(game, EXIT_FAILURE, "Allocation error");
	x = 0;
	while (x < WIDTH)
	{
		game->cam->rays[x] = (t_ray *)ft_calloc(sizeof(t_ray), 1);
		if (game->cam->rays[x] == NULL)
			clear_and_exit(game, EXIT_FAILURE, "Allocation error");
		x++;
	}
}

void	init(t_game *game)
{
	game->mlx = mlx_init(WIDTH + HEIGHT, HEIGHT, "Cub3d", false);
	if (game->mlx == NULL)
		clear_and_exit(game, EXIT_FAILURE, "Allocation error");
	game->player = ft_calloc(sizeof(t_player), 1);
	if (game->player == NULL)
		clear_and_exit(game, EXIT_FAILURE, "Allocation error");
	game->unit_size = 200;
	game->player->move_speed = game->unit_size / 10;
	find_player_spawn(game);
	init_minimap(game);
	game->cam = ft_calloc(sizeof(t_cam), 1);
	if (game->cam == NULL)
		clear_and_exit(game, EXIT_FAILURE, "Allocation error");
	game->cam->fov = M_PI / 3;
	game->cam->tanfov = tan(game->cam->fov / 2) * 2;
	allocate_rays(game);
	calculate_cam_angles(game);
	game->screen = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->cam->col = ft_calloc(sizeof(size_t), HEIGHT);
	if (game->cam->col == NULL)
		clear_and_exit(game, EXIT_FAILURE, "Allocation error");
	set_row_lengths(game);
}

void	set_row_lengths(t_game *game)
{
	size_t	y;

	game->map->row_lens = ft_calloc(sizeof(size_t), game->map->height);
	if (game->map->row_lens == NULL)
		clear_and_exit(game, EXIT_FAILURE, "Allocation error");
	y = 0;
	while (y < game->map->height)
	{
		game->map->row_lens[y] = ft_strlen(game->map->map[y]);
		y++;
	}
}

void	calculate_cam_angles(t_game *game)
{
	int		x;
	float	val;

	x = 0;
	while (x < WIDTH)
	{
		val = -(game->cam->fov / 2) + (x * (game->cam->fov) / WIDTH);
		game->cam->rays[x]->ray_angle = val;
		x++;
	}
}
