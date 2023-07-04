/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:41 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:20:42 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "struct.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "parser/parse.h"
# include "validater/validate.h"
# include "graphics/render.h"
# include "image/imagemanip.h"
# include "minimap/minimap.h"
# include "../lib/libft/libft.h"
# include "util/util.h"
# include "hooks/hooks.h"
# include "init/init.h"
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720

#endif
