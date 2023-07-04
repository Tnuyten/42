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
# include <math.h>

#define WIDTH 1280
#define HEIGHT 720

t_uint	*get_column_from_texture(t_game* game, t_uint screen_x, t_uint wall_height);
// void	image_put_pixel(t_img *data, int x, int y, int color);

#endif
