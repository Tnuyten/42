#ifndef IMAGEMANIP_H
# define IMAGEMANIP_H

#include "../cub3d.h"
#include <math.h>

mlx_image_t*	ft_scale_image(mlx_t *mlx, mlx_image_t *image, float scale);
mlx_image_t*	ft_rotate_image(mlx_t *mlx, mlx_image_t *image, int angle);
mlx_image_t*	ft_resize_image(mlx_t *mlx, mlx_image_t *image, t_uint nwidth, t_uint nheight);

void			clear_image(mlx_image_t *img, t_uint color);

#endif
