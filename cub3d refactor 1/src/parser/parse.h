/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:16 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/18 23:48:23 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../cub3d.h"
# include <string.h>
# include "../../src/gnl/get_next_line.h"
# include "../../lib/libft/libft.h"
# include "../struct.h"

// parse
int			parse_map(char *map_path, t_map *map);
int			parse_loop(t_map *map, int fd);
int			check_sep(char *line);

// util
int			is_texture_line(char *line);
int			is_color_line(char *line);
int			is_empty_line(char *line);
int			is_map_line(char *line);
size_t		ft_fnl(char *s);

// parse_line.c
uint32_t	parse_color(char *line);
int			parse_texture(t_map *map, char *line);
int			parse_line(t_map *map, char *line, size_t *row, int *mode);

#endif
