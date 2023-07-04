#ifndef PARSE_H
# define PARSE_H

# include "../cub3d.h"
# include <string.h>
# include "../../src/gnl/get_next_line.h"
# include "../../lib/libft/libft.h"
# include "../struct.h"

// parse
int		parse_map(char *map_path, t_map *map);

// util
int		is_texture_line(char *line);
int		is_color_line(char *line);
int		is_empty_line(char *line);
int		is_map_line(char *line);
int		ft_fnl(char *s);

// debug
void	print_map(char **map);

#endif
