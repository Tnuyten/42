/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:26:14 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/19 15:26:19 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"

int	char_check(t_map *map)
{
	size_t	x;
	size_t	y;
	char	c;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < ft_strlen(map->map[y]))
		{
			c = map->map[y][x];
			if (c == ' ')
			{
				map->map[y][x] = '1';
				c = '1';
			}
			if (!(c == '0' || c == '1' || is_player_spawn(c)))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
