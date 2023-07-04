/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:14 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/18 23:56:14 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	smh_loop(int fd, size_t *height, size_t *width)
{
	char	*line;
	int		status;

	while (1)
	{
		line = NULL;
		status = get_next_line(fd, &line);
		if (line == NULL || status == -1)
			return (-1);
		if (is_map_line(line))
		{
			(*height)++;
			if (ft_strlen(line) > *width)
				*width = ft_strlen(line) - 1;
		}
		free(line);
		if (status == 0)
			break ;
	}
	return (0);
}

static int	set_map_height(char *map_path, size_t *height, size_t *width)
{
	int		fd;

	*height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nError on opening map file: ");
		return (-1);
	}
	if (smh_loop(fd, height, width) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	parse_map(char *map_path, t_map *map)
{
	int	fd;

	if (set_map_height(map_path, &map->height, &map->width) == -1)
		return (-1);
	if (map->height == 0 || map->width == 0)
		return (-1);
	map->map = (char **)ft_calloc((int)map->height, sizeof(char *));
	if (map->map == NULL)
		return (-1);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nError on opening map file: ");
		return (-1);
	}
	if (parse_loop(map, fd) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (!map->ceil_color || !map->floor_color)
		return (-1);
	return (0);
}

int	parse_loop(t_map *map, int fd)
{
	char	*line;
	size_t	row;
	int		mode;
	int		status;

	row = 0;
	mode = 0;
	while (1)
	{
		status = get_next_line(fd, &line);
		if (line == NULL || status == -1)
			return (-1);
		line[ft_fnl(line)] = '\0';
		if (parse_line(map, line, &row, &mode) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		if (status <= 0)
			break ;
	}
	if (!map->north || !map->east || !map->south || !map->west)
		return (-1);
	return (0);
}

int	check_sep(char *line)
{
	int	i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != ',')
		return (-1);
	i++;
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		return (-1);
	return (i);
}
