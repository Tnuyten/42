/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:22:17 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/08 17:18:04 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	stop(char *message, int mode, t_map *map)
{
	if (mode)
	{
		free(map->map);
		free(map->color_map);
	}
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	free_all(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	free(mlx->map->map);
	free(mlx->map->color_map);
	free(mlx);
}

// 0: Program ran correctly.
// 1: Failed to allocate map.
// 2: Failed to allocate color_map.
// 3: Map width or height is zero.
// -1: Error populating map, possible uneven lines.
static void	free_some(int ret, t_map *map)
{
	if (ret == 0 || ret == 1 || ret == 3)
		return ;
	if (ret == -1)
	{
		free(map->map);
		free(map->color_map);
	}
	else if (ret == 2)
	{
		free(map->map);
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	*mlx;
	int		ret;

	if (argc != 2)
		stop("Incorrect number of arguments", 0, NULL);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".fdf\0", 4) != 0)
		stop("Not a .fdf file", 0, NULL);
	ret = make_map(argv, &map);
	free_some(ret, &map);
	if (ret != 0)
		return (EXIT_FAILURE);
	mlx = init_mlx();
	if (mlx == NULL || mlx->mlx == NULL)
		stop("Could not initialize MLX", 1, &map);
	mlx->map = &map;
	mlx_hook(mlx->win, 17, 0, close_window_button, mlx);
	mlx_key_hook(mlx->win, keyhooks, mlx);
	redraw(mlx);
	mlx_loop(mlx->mlx);
	free_all(mlx);
	return (EXIT_SUCCESS);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
	{
		free(mlx);
		return (NULL);
	}
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fil de fer");
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	return (mlx);
}
