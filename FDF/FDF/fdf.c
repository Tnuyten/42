/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:22:17 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/01 15:40:32 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	stop(char *message)
{
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

static void	free_some(int ret, t_mlx *mlx)
{
	if (ret == 0)
		return ;
	if (ret == -1)
	{
		free_all(mlx);
	}
	else if (ret == 1 || ret == 3)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		free(mlx);
	}
	else if (ret == 2)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		free(mlx->map);
		free(mlx);
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	*mlx;
	char	*ptr;
	int		ret;

	if (argc != 2)
		stop("Incorrect number of arguments");
	ptr = ft_strchr(argv[1], '.');
	if (ptr == NULL || ptr[1] != 'f' || ptr[2] != 'd' || ptr[3] != 'f')
		stop("Incorrect argument");
	mlx = init_mlx();
	if (mlx == NULL || mlx->mlx == NULL)
		stop("Could not initialize MLX");
	mlx->map = &map;
	ret = make_map(argv, mlx->map);
	free_some(ret, mlx);
	if (ret != 0)
		return (EXIT_FAILURE);
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
		return (NULL);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Fil de fer");
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	return (mlx);
}
