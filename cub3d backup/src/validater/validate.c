#include "validate.h"

static int	check_edge_for_zeroes(t_map *map);
static void	flood_fill_map(t_map *map, t_uint x, t_uint y);
static int	count_player_spawns(t_map *map);

int	validate(t_map *map)
{
	size_t	x;
	size_t	y;

	if (count_player_spawns(map) != 1)
		return (false);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < ft_strlen(map->map[y]))
		{
			if (is_player_spawn(map->map[y][x]))
				flood_fill_map(map, x, y);
			x++;
		}
		y++;
	}
	return (!check_edge_for_zeroes(map));
}

// Returns true if the edge of the map contains any zeroes.
static int	check_edge_for_zeroes(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < ft_strlen(map->map[y]))
		{
			if (map->map[y][x] == '0' && cell_is_edge(map, x, y))
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

// From the given coordinate, change the current '0' cell and all adjacent '0'
// cells from '0' to '8' (arbitrarily chosen).
static void	flood_fill_map(t_map *map, t_uint x, t_uint y)
{
	char	**grid;

	grid = map->map;
	if (out_of_bounds(map, x, y))
		return ;
	if (grid[y][x] != '0' && !is_player_spawn(grid[y][x]))
		return ;
	if (cell_is_edge(map, x, y))
		return ;
	if (!is_player_spawn(grid[y][x]))
		grid[y][x] = '8';

	flood_fill_map(map, x + 1, y);
	flood_fill_map(map, x - 1, y);
	flood_fill_map(map, x, y + 1);
	flood_fill_map(map, x, y - 1);
}

// Iterate over the map, and count the player spawns.
static int	count_player_spawns(t_map *map)
{
	size_t	y;
	size_t	x;
	int		count;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < ft_strlen(map->map[y]))
		{
			if (is_player_spawn(map->map[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
