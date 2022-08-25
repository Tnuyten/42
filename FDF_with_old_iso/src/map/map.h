/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:29:12 by tnuyten           #+#    #+#             */
/*   Updated: 2022/08/25 17:41:34 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>
# include "../../fdf.h"
# include "../iso/iso.h"
# include "../math/math.h"

void	make_map(char **argv, t_mlx *mlx);

#endif