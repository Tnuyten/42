/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:26:08 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/25 17:40:43 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISO_H
# define ISO_H

# include "../../fdf.h"

t_coord	*cart_to_iso(int x, int y, t_map map);
t_coord	*scale_and_center(int x, int y, t_map map, t_coord *co);
t_coord	*first_rotation(t_coord *co, t_map map);
t_coord	*second_rotation(t_coord *co);
t_coord	*add_height(int x, int y, t_coord *co, t_map map);

#endif