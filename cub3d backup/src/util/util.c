#include "util.h"

// Returns true if the given character is a player spawn symbol.
int is_player_spawn(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (true);
	return (false);
}

// Returns true if an edge cell of the map is a zero.
int	cell_is_edge(t_map *map, t_uint x, t_uint y)
{
	if (out_of_bounds(map, x, y - 1))
		return (true);
	if (out_of_bounds(map, x, y + 1))
		return (true);
	if (out_of_bounds(map, x + 1, y))
		return (true);
	if (out_of_bounds(map, x - 1, y))
		return (true);
	return (false);
}

// Returns true if the given coordinates lie outside the bounds of the given
// map.
int	out_of_bounds(t_map *map, t_uint x, t_uint y)
{
	if (y >= map->height)
		return (true);
	if (x >= ft_strlen(map->map[y]))
		return (true);
	return (false);
}
