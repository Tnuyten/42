/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:29:14 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/27 15:49:54 by tnuyten          ###   ########.fr       */
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

	set_w_h(argv, map);
	if (map->height == 0 || map->width == 0)
		return ;
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
		ft_memcpy(map->map + width * i++, map_line, sizeof(int) * width);
		free(line);
		free(map_line);
	}
	return ;
}

void set_map_values(t_map *map)
{
	int width = map->width;
	int height = map->height;

	map->tile_width = WIDTH / max(width, height);
	map->tile_length = HEIGHT / max(width, height);
	map->tile_height = abs(map->tile_width + map->tile_length) / 4;
	map->tile_width_half = map->tile_width / 2;
	map->tile_length_half = map->tile_length / 2;
	// map->iso_x_origin = 0;
	// map->iso_y_origin = 0;
	map->map_screen_width = cart_to_iso(width - 1, 0, *map)->x - cart_to_iso(0, height - 1, *map)->x;
	map->map_screen_height = cart_to_iso(width - 1, height - 1, *map)->y - cart_to_iso(0, 0, *map)->y;
	map->iso_x_origin = WIDTH / 2 - ((width - height) * map->tile_width_half / 2);
	map->iso_y_origin = (HEIGHT - map->map_screen_height) / 2;
	map->steepness = 1;
	// map->iso_y_origin = map->tile_length_half + (abs(height - width) * map->tile_length_half) / 2;

	printf("\niso_x_origin: %d\n", map->iso_x_origin);
	printf("Screen left to left corner = %d\n", cart_to_iso(0, height - 1, *map)->x);
	printf("Screen right to right corner = %d\n", WIDTH - cart_to_iso(width - 1, 0, *map)->x);
	printf("Screen top to top corner = %d\n", cart_to_iso(0, 0, *map)->y);
	printf("Screen bottom to bottom corner = %d\n", HEIGHT - cart_to_iso(width - 1, height - 1, *map)->y);
	printf("map length top to bottom: %d\n", cart_to_iso(width - 1, height - 1, *map)->y - cart_to_iso(0, 0, *map)->y);
	printf("1200 - dy = %d\n", HEIGHT - (cart_to_iso(width - 1, height - 1, *map)->y - cart_to_iso(0, 0, *map)->y));
	printf("width half: %d\n", map->tile_width_half);
	printf("length half: %d\n", map->tile_length_half);
	printf("map_screen_height: %d\n",map->map_screen_height);
	printf("map_screen_width: %d\n",map->map_screen_width);
	printf("width: %d\n", map->tile_width);
	printf("length: %d\n\n", map->tile_length);
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