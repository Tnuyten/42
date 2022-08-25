/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:29:14 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/25 18:28:26 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	*str_to_int_arr(char *line, int *width)
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
		while (*line == ' ')
			line ++;
		if (*line == '\0' || *line == '\n')
			break ;
		map_line_temp[i++] = ft_atoi(line);
		while (*line != ' ' && *line != '\0' && *line != '\n')
			line ++;
	}
	map_line = malloc(sizeof(int) * i);
	ft_memcpy(map_line, map_line_temp, sizeof(int) * i);
	free(map_line_temp);
	*width = i;
	return (map_line);
}

static void	set_w_h(char **argv, t_map *map)
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

static void	fill_map(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		width;
	int		*map_line;
	int		i;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_line = str_to_int_arr(line, &width);
		free(line);
		if (map_line == NULL)
			break ;
		ft_memcpy(map->map + width * i++, map_line, sizeof(int) * width);
		free(map_line);
	}
	close(fd);
}

// The order here matters! a lot!
static void	set_map_values(t_map *map)
{
	t_coord	*right;
	t_coord	*left;
	t_coord	*top;
	t_coord	*bottom;

	map->tile_width = WIDTH / max(map->width, map->height);
	map->tile_length = HEIGHT / max(map->width, map->height);
	map->tile_height = abs(map->tile_width + map->tile_length) / 4;
	map->tile_width_half = map->tile_width / 2;
	map->tile_length_half = map->tile_length / 2;
	right = cart_to_iso(map->width - 1, 0, *map);
	left = cart_to_iso(0, map->height - 1, *map);
	bottom = cart_to_iso(map->width - 1, map->height - 1, *map);
	top = cart_to_iso(0, 0, *map);
	map->map_screen_width = right->x - left->x;
	map->map_screen_height = bottom->y - top->y;
	map->iso_x_origin = WIDTH / 2 - ((map->width - map->height)
			* map->tile_width_half / 2);
	map->iso_y_origin = (HEIGHT - map->map_screen_height) / 2;
	free(right);
	free(left);
	free(top);
	free(bottom);
}

void	make_map(char **argv, t_mlx *mlx)
{
	mlx->map->steepness = 1;
	mlx->map->iso_x_origin = 0;
	mlx->map->iso_y_origin = 0;
	mlx->map->x_offset = 0;
	mlx->map->y_offset = 0;
	mlx->map->angle = 45;
	set_w_h(argv, mlx->map);
	mlx->map->map = malloc(sizeof(int) * mlx->map->width * mlx->map->height);
	if (mlx->map->map == NULL)
		return ;
	ft_bzero(mlx->map->map, sizeof(int) * mlx->map->width * mlx->map->height);
	if (mlx->map->height == 0 || mlx->map->width == 0)
	{
		free_all(mlx);
		exit(EXIT_FAILURE);
	}
	set_map_values(mlx->map);
	fill_map(argv, mlx->map);
	redraw(mlx);
}
