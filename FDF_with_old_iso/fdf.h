/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:22:58 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/25 18:23:44 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://clintbellanger.net/articles/isometric_math/
// find . -name "*.c" -not -path "./lib/mlx/*" | xargs norminette
// find . -name "*.h" -not -path "./lib/mlx/*" | xargs norminette

#ifndef FDF_H
# define FDF_H

# include "structs.h"
# include "lib/mlx/mlx.h"
# include "lib/gnl/get_next_line.h"
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include "src/line/line.h"
# include "src/iso/iso.h"
# include "src/map/map.h"
# include "src/math/math.h"
# include "src/draw/draw.h"
# include "src/hooks/hooks.h"

# define WIDTH 1920
# define HEIGHT 1200
// # define RED 0x00FF0000
// # define GREEN 0x0000FF00
// # define BLUE 0x000000FF
// # define RG 0x00FFFF00
// # define RB 0x00FF00FF
// # define GB 0x0000FFFF
// # define WHITE 0x00FFFFFF

t_mlx	*init_mlx(void);
void	free_all(t_mlx *mlx);

#endif