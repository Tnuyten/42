/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:28:03 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/19 18:57:30 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "../fdf.h"

void draw_horizontal_line(t_data img, t_coord start, t_coord end, int color);
void draw_vertical_line(t_data img, t_coord start, t_coord end, int color);
void image_draw_small_m_line(t_data img, t_coord start, t_coord end, int color);
void image_draw_big_m_line(t_data img, t_coord start, t_coord end, int color);
void image_draw_line(t_data img, t_coord start, t_coord end, int color);

#endif