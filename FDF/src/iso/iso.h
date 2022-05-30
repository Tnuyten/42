/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:26:08 by tnuyten           #+#    #+#             */
/*   Updated: 2022/05/27 13:28:58 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_H
# define COORD_H

# include "../../fdf.h"

t_coord	*cart_to_iso(int x, int y, t_map map);
void iso_add_height(int x, int y, t_map map, t_coord *co);


#endif