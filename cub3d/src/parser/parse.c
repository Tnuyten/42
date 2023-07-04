#include "parse.h"

//#TODO fix segfault on missing color.
// TODO check for missing color lines/parts.

// First three sets of digits on the line are the RGB color values.
static t_uint	parse_color(char *line) 
{
	int		i;
	t_uint	color;

	i = 0;
	color = 0xFF;
	while (!ft_isdigit(line[i]))
		i++;
	color += ft_atoi(&line[i]) << 24;
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	color += ft_atoi(&line[i]) << 16;
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	color += ft_atoi(&line[i]) << 8;
	free(line);
	return (color);
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

static void	parse_texture(t_map *map, char *line)
{
	char			*p1;
	char			*p2;
	char			*p3;
	char			*p4;
	mlx_texture_t	*tex;

	p1 = ft_strnstr(line, "NO ", ft_strlen(line));
	p2 = ft_strnstr(line, "SO ", ft_strlen(line));
	p3 = ft_strnstr(line, "EA ", ft_strlen(line));
	p4 = ft_strnstr(line, "WE ", ft_strlen(line));
	printf("loading png: %s\n", line);
	tex = mlx_load_png(clear_path(line));

	if (p1 && map->north == NULL)
		map->north = tex;
	else if (p2 && map->south == NULL)
		map->south = tex;
	else if (p3 && map->east == NULL)
		map->east = tex;
	else if (p4 && map->west == NULL)
		map->west = tex;
	free(line);
}

// All lines except map lines are freed.
// Texture and color lines are freed in their own functions.
static int	parse_line(t_map *map, char *line, t_uint *row, int *mode)
{
	if (is_texture_line(line))
		parse_texture(map, line);
	else if (ft_strnstr(line, "F ", ft_strlen(line)))
		map->floor_color = parse_color(line);
	else if (ft_strnstr(line, "C ", ft_strlen(line)))
		map->ceil_color = parse_color(line);
	else
	{
		if (is_empty_line(line))
		{
			free(line);
			if (*mode != 0)
				return (-1);
		}
		else
		{
			map->map[(*row)++] = line;
			*mode = 1;
		}
	}
	return (0);
}

static int	set_map_height(char *map_path, t_uint *height, t_uint *width)
{
	int		fd;
	char	*line;

	*height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error on opening map file: ");
		return (-1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_map_line(line))
		{
			(*height)++;
			if (ft_strlen(line) > *width)
				*width = ft_strlen(line) - 1;
		}
		free(line);
	}
	close(fd);
	return (0);
}

int	parse_map(char *map_path, t_map *map)
{
	int		fd;
	t_uint	row;
	char	*full_line;
	char	*line;
	int		mode;

	if (set_map_height(map_path, &map->height, &map->width) == -1)
		return (-1);
	map->map = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (map->map == NULL)
		return (1);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error on opening map file: ");
		return (-1);
	}
	row = 0;
	mode = 0;
	while (1)
	{
		full_line = get_next_line(fd);
		if (!full_line)
			return (0);
		line = ft_substr(full_line, 0, ft_fnl(full_line));
		free(full_line);
		if (line == NULL)
			return (-1);
		if (parse_line(map, line, &row, &mode) == -1)
			return (-1);
	}
	close(fd);
	return (0);
}
