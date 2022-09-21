/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:29:14 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/08 17:17:16 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	*str_to_int_arr(char *line, t_map *map)
{
	int	*map_line;
	int	i;

	i = 0;
	map_line = malloc(sizeof(int) * map->width);
	if (map_line == NULL)
		return (NULL);
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (*line == '\0' || *line == '\n')
			break ;
		map_line[i++] = ft_atoi(line);
		while (*line != ' ' && *line != '\0' && *line != '\n')
			line++;
	}
	if (i != map->width)
	{
		free(map_line);
		return (NULL);
	}
	return (map_line);
}

// line += 3 to skip ",0x"
static void	set_color(char *line, int row, int width, t_map *map)
{
	int	color;
	int	i;

	i = 0;
	while (line != NULL)
	{
		while (ft_isspace(*line))
			line++;
		while (ft_isdigit(*line))
			line++;
		if (*line == ',')
		{
			line += 3;
			color = ft_atoi_base(line, 16);
			map->color_map[row * width + i] = color;
		}
		while (ft_isalnum(*line))
			line++;
		if (*line == '\n' || *line == '\0')
			return ;
		i++;
	}
}

static int	stop(char *line, int *map_line, int fd)
{
	free(map_line);
	free(line);
	close(fd);
	ft_printf("%s\n", "Error: Map is malformed");
	return (-1);
}

static int	fill_map(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		width;
	int		*map_line;
	int		row;

	fd = open(argv[1], O_RDONLY);
	row = 0;
	width = map->width;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_line = str_to_int_arr(line, map);
		if (map_line == NULL)
			return (stop(line, map_line, fd));
		if (ft_strchr(line, ',') != NULL)
			set_color(line, row, width, map);
		free(line);
		ft_memcpy(map->map + width * row++, map_line, sizeof(int) * width);
		free(map_line);
	}
	close(fd);
	return (0);
}

int	make_map(char **argv, t_map *map)
{
	int		tile_width;
	int		tile_length;

	set_w_h(argv, map);
	if (map->width == 0 || map->height == 0)
		return (3);
	map->map = malloc(sizeof(int) * map->width * map->height);
	if (map->map == NULL)
		return (1);
	ft_bzero(map->map, sizeof(int) * map->width * map->height);
	map->color_map = malloc(sizeof(int) * map->width * map->height);
	if (map->color_map == NULL)
	{
		return (2);
	}
	ft_bzero(map->color_map, sizeof(int) * map->width * map->height);
	tile_width = WIDTH / max(map->width, map->height);
	tile_length = HEIGHT / max(map->width, map->height);
	map->tile_height = abs(tile_width + tile_length) / 4;
	if (fill_map(argv, map) == -1)
	{
		return (-1);
	}
	return (0);
}
