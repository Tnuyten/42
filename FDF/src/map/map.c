/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:29:14 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/30 18:49:30 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

# include <stdio.h>

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
		while (*line == ' ')
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

// Initialize the map int array, map width and height, and fill the map.
void	fill_map(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		width;
	int		*map_line;
	int		i;

	map->map = malloc(sizeof(int) * map->width * map->height);
	if (map->map == NULL)
		return ;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_line = str_to_int_arr(line, &width);
		free(line);
		if(map_line == NULL)
			break ;
		ft_memcpy(map->map + width * i++, map_line, sizeof(int) * width);
		free(map_line);
	}
	close(fd);
	return ;
}

// The order here matters!
void set_map_values(t_map *map)
{
	t_coord *right;
	t_coord *left;
	t_coord *top;
	t_coord *bottom;

	map->tile_width = WIDTH / max(map->width, map->height);
	map->tile_length = HEIGHT / max(map->width, map->height);
	map->tile_height = abs(map->tile_width + map->tile_length) / 4;
	map->tile_width_half = map->tile_width / 2;
	map->tile_length_half = map->tile_length / 2;
	map->iso_x_origin = 0;
	map->iso_y_origin = 0;
	right = cart_to_iso(map->width - 1, 0, *map);
	left = cart_to_iso(0, map->height - 1, *map);
	bottom = cart_to_iso(map->width - 1, map->height - 1, *map);
	top = cart_to_iso(0, 0, *map);
	map->map_screen_width = right->x - left->x;
	map->map_screen_height = bottom->y - top->y;
	map->iso_x_origin = WIDTH / 2 - ((map->width - map->height) * map->tile_width_half / 2);
	map->iso_y_origin = (HEIGHT - map->map_screen_height) / 2;
	map->steepness = 1;

	free(right);
	free(left);
	free(top);
	free(bottom);

	right = cart_to_iso(map->width - 1, 0, *map);
	left = cart_to_iso(0, map->height - 1, *map);
	bottom = cart_to_iso(map->width - 1, map->height - 1, *map);
	top = cart_to_iso(0, 0, *map);

	printf("right:  (%d,%d)\n", right->x, right->y);
	printf("left:   (%d,%d)\n", left->x, left->y);
	printf("top:    (%d,%d)\n", top->x, top->y);
	printf("bottom: (%d,%d)\n", bottom->x, bottom->y);


	printf("\niso_x_origin: %d\n", map->iso_x_origin);
	printf("Screen left to left corner = %d\n", left->x);
	printf("Screen right to right corner = %d\n", WIDTH - right->x);
	printf("Screen top to top corner = %d\n", top->y);
	printf("Screen bottom to bottom corner = %d\n", HEIGHT - bottom->y);
	printf("map length top to bottom: %d\n", bottom->y - top->y);
	printf("1200 - mlttb = %d\n", HEIGHT - (bottom->y - top->y));
	printf("width half: %d\n", map->tile_width_half);
	printf("length half: %d\n", map->tile_length_half);
	printf("map_screen_height: %d\n",map->map_screen_height);
	printf("map_screen_width: %d\n",map->map_screen_width);
	printf("width: %d\n", map->tile_width);
	printf("length: %d\n\n", map->tile_length);

	free(right);
	free(left);
	free(top);
	free(bottom);
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
			printf("%2d ", map.map[j + i * map.width]);
			j++;
		}
		printf("\n");
		i++;
	}
}

// void	draw_map(t_mlx mlx)
// {
// 	int	i;
// 	int	j;
// 	t_coord start;
// 	t_coord *end = cart_to_iso(0, 0, *mlx.map);
// 	i = 0;
// 	while (i < mlx.map->height)
// 	{
// 		j = 0;
// 		while (j < mlx.map->width)
// 		{
// 			start = *end;
// 			free(end);
// 			end = cart_to_iso(j, i, *mlx.map);
// 			iso_add_height(j, i, *mlx.map, end);
// 			printf("%2d:(%4d,%4d)", mlx.map->map[j + i * mlx.map->width], end->x, end->y);
// 			if (j == 0 && i != 0)
// 			{
// 				j++;
// 				continue ;
// 			}
// 			image_draw_line(mlx, start, *end, 0x00FF0000);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	free(end);
//
//
// 	end = cart_to_iso(0, 0, *mlx.map);
// 	i = 0;
// 	while (i < mlx.map->width)
// 	{
// 		j = 0;
// 		while (j < mlx.map->height)
// 		{
// 			start = *end;
// 			free(end);
// 			end = cart_to_iso(i, j, *mlx.map);
// 			iso_add_height(i, j, *mlx.map, end);
// 			if (j == 0 && i != 0)
// 			{
// 				j++;
// 				continue;
// 			}
// 			image_draw_line(mlx, start, *end, 0x00FF0000);
// 			j++;
// 		}
// 		i++;
// 	}
// 	free(end);
// }