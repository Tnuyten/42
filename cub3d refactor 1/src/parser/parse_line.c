/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:09 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/19 18:06:04 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

uint32_t	parse_color(char *line)
{
	int			skipped;
	uint32_t	val[3];
	int			i;

	while (*line == ' ')
		line++;
	if (!ft_isdigit(*line))
		return (256);
	i = 0;
	while (i < 2)
	{
		val[i] = (uint32_t)ft_atoi(line);
		skipped = check_sep(line);
		if (val[i++] >= 256 || skipped == -1)
			return (256);
		line += skipped;
	}
	val[2] = (uint32_t)ft_atoi(line);
	while (!ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	if (*line == '\0' || val[2] >= 256)
		return (256);
	return ((val[0] << 24) + (val[1] << 16) + (val[2] << 8) + 0xFF);
}

static char	*clear_path(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	return (&line[i]);
}

mlx_texture_t	*load_tex(char *line)
{
	mlx_texture_t	*tex;

	tex = mlx_load_png(clear_path(line));
	return (tex);
}

int	parse_texture(t_map *map, char *line)
{
	int				p1;
	int				p2;
	int				p3;
	int				p4;

	p1 = ft_strnstr(line, "NO ", ft_strlen(line)) == line;
	p2 = ft_strnstr(line, "SO ", ft_strlen(line)) == line;
	p3 = ft_strnstr(line, "EA ", ft_strlen(line)) == line;
	p4 = ft_strnstr(line, "WE ", ft_strlen(line)) == line;
	if (!p1 && !p2 && !p3 && !p4)
		return (1);
	if (p1 && map->north == NULL)
		map->north = load_tex(line);
	else if (p2 && map->south == NULL)
		map->south = load_tex(line);
	else if (p3 && map->east == NULL)
		map->east = load_tex(line);
	else if (p4 && map->west == NULL)
		map->west = load_tex(line);
	return (0);
}

int	parse_line(t_map *map, char *line, size_t *row, int *mode)
{
	if (is_texture_line(line))
	{
		if (parse_texture(map, line) == -1 || *mode == 1)
			return (-1);
	}
	else if (ft_strnstr(line, "F ", ft_strlen(line)) == line)
	{
		if (*mode == 1 || map->floor_color != 0)
			return (-1);
		map->floor_color = parse_color(line + 2);
	}
	else if (ft_strnstr(line, "C ", ft_strlen(line)) == line)
	{
		if (*mode == 1 || map->ceil_color != 0)
			return (-1);
		map->ceil_color = parse_color(line + 2);
	}
	else if (is_empty_line(line))
		return (-(*mode));
	else
	{
		map->map[(*row)++] = ft_strdup(line);
		*mode = 1;
	}
	return (-(map->floor_color == 256 || map->ceil_color == 256));
}
