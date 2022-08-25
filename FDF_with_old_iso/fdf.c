/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:22:17 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/25 18:18:03 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	*mlx;

	if (argc != 2)
	{
		ft_printf("%s\n", "Incorrect argument");
		exit(EXIT_FAILURE);
	}
	mlx = init_mlx();
	if (mlx == NULL || mlx->mlx == NULL)
		exit(EXIT_FAILURE);
	mlx->map = &map;
	make_map(argv, mlx);
	mlx_hook(mlx->win, 17, 0, close_window_button, mlx);
	mlx_key_hook(mlx->win, keyhooks, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
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
		return (NULL);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FDF");
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	return (mlx);
}

void	free_all(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	free(mlx->map->map);
	free(mlx);
}
