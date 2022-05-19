/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:22:17 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/19 20:07:50 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
https://github.com/codam-coding-college/MLX42/wiki/Images
*/

#include "fdf.h"
#include <stdio.h>
#include <math.h>
# include "line/line.h"

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define RG 0x00FFFF00
# define RB 0x00FF00FF
# define GB 0x0000FFFF
# define WHITE 0x00FFFFFF


int	close_window_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_window_button(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
}

void	image_pixel_put(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (x * (img.bits_per_pixel / 8) + y * img.line_length);
	*(unsigned int *)dst = color;
}

void	print_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			printf("%2d ", *(map.map + j + i * map.height));
			j++;
		}
		printf("\n");
		i++;
	}
}

int	*str_to_int_arr(char *line, int *width)
{
	int	*map_line_temp;
	int	*map_line;
	int	i;

	i = 0;
	map_line_temp = malloc(sizeof(int) * ft_strlen(line));
	if (map_line_temp == NULL)
		return (NULL);
	while (*line)
	{
		if (*line == ' ')
			line ++;
		if (*line == '\0' || *line == '\n')
			break ;
		map_line_temp[i++] = ft_atoi(line);
		while (ft_isdigit(*line) || *line == '-')
			line ++;
	}
	map_line = malloc(sizeof(int) * i);
	ft_memcpy(map_line, map_line_temp, sizeof(int) * i);
	free(map_line_temp);
	*width = i;
	return (map_line);
}

void	set_w_h(char **argv, t_map *map)
{
	int		fd;
	int		height;
	char	*line;
	int		*map_line;
	int		width;

	height = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_line = str_to_int_arr(line, &width);
		free(line);
		if (map_line == NULL)
			return ;
		free(map_line);
		height++;
	}
	map->height = height;
	map->width = width;
	close(fd);
}

void	fill_map(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		width;
	int		*map_line;
	int		i;

	set_w_h(argv, map);
	if (map->height == 0 || map->width == 0)
		return ;
	map->map = malloc(sizeof(int) * map->width * map->height);
	if (map == NULL)
		return ;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_line = str_to_int_arr(line, &width);
		ft_memcpy(map->map + width * i++, map_line, sizeof(int) * width);
		free(line);
		free(map_line);
	}
	return ;
}

void get_iso (int x, int y, t_map map, t_coord *co)
{
	int xx = x * 100; //6 -> 600
	int yy = y * 100; //1 -> 100

	co->x = (xx - map.map[x + y * map.width] * 100) / sqrt(2);
	co->y = (xx + 2*yy + map.map[x + y * map.width] * 100) / sqrt(6);
}

// void connect_neighbours(t_data img, int x, int y, color)
// {
// 	if(x == 0 && y == 0)
// 	{
// 		image_draw_line(img, x, y, color);
// 		image_draw_line(img, x, y, color);
// 	}
// 	else if(x == 0)
// 	{
//
// 	}
// 	else if(y == 0)
// 	{
//
// 	}
// 	else
// 	{
//
// 	}
// }

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		printf("%s\n", "Incorrect argument");
		exit(EXIT_FAILURE);
	}
	fill_map(argv, &map);
	if (map.height == 0 || map.width == 0)
		exit(EXIT_FAILURE);

	print_map(map);

	t_mlx mlx = *init_mlx();
	t_coord start = {0,0};

	int	i;
	int	j;
	i = 0;
	t_coord iso = start;

	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			start = iso;

			get_iso(j, i, map, &iso);
			image_draw_line(mlx.img, start, iso, 0x00FF0000 - 0x00100000 * j + 0x00001000 * j + 0x00000010 * i);
			// image_pixel_put(mlx.img, iso.x, iso.y, 0x00FF00FF);
			printf("%2d:(%d, %d)", *(map.map + j + i * map.height), iso.x, iso.y);
			j++;
		}
		printf("\n");
		i++;
	}

	// t_coord end = {636, 367};
	// image_draw_line(mlx.img, start, end, RED);
	// image_pixel_put(mlx.img, end.x, end.y, RB);
	//
	// t_coord end2 = {69, 420};
	// image_draw_line(mlx.img, start, end2, BLUE);
	// end2.x = 231;
	// image_draw_line(mlx.img, start, end2, RG);
	//
	// end2.y = 1000;
	// end2.x = 440;
	// image_draw_line(mlx.img, start, end2, 0x00FFFFFF);

	mlx_hook(mlx.win, 17, 0, close_window_button, &mlx);
	mlx_key_hook(mlx.win, close_window_keypress, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx);

	free(&mlx);

	return (EXIT_SUCCESS);
}

t_mlx	*init_mlx()
{
	t_mlx* mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FDF by Thibauld Nuyten");
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);

	return (mlx);
}
