/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:25:33 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/30 21:25:34 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	set_width(char **argv, t_map *map)
{
	int		fd;
	int		width;
	char	*line;

	width = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return ;
	while (line != NULL && *line != '\n' && *line != '\0')
	{
		while (ft_isspace(*line))
			line++;
		while (*line == '-' || *line == '+')
			line++;
		while (ft_isalnum(*line) || *line == ',')
			line++;
		width++;
	}
	map->width = width;
	close(fd);
}

void	set_w_h(char **argv, t_map *map)
{
	int		fd;
	int		height;
	char	*line;

	height = 1;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	set_width(argv, map);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		height++;
	}
	map->height = height;
	close(fd);
}
