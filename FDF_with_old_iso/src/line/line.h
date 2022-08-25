/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:28:03 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/25 16:06:05 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "../../fdf.h"
# include "../draw/draw.h"
# include "math.h"

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;
}	t_line;

void	image_draw_line(t_mlx mlx, t_coord start, t_coord end, int color);

#endif