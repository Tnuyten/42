#ifndef UTIL_H
# define UTIL_H

# include "../cub3d.h"

int	is_player_spawn(char c);
int	cell_is_edge(t_map *map, t_uint x, t_uint y);
int	out_of_bounds(t_map *map, t_uint x, t_uint y);

#endif
