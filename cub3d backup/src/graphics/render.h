#ifndef RENDER_H
# define RENDER_H

# include "../cub3d.h"

mlx_image_t *make_background(t_game *game);
void draw_ray(t_game *game);
void draw_screen(t_game *game);
void	line_length(t_game *game, t_uint screen_x);
int	get_tex_color(mlx_texture_t *tex, struct s_coord *pos);
mlx_image_t	*texture_pixels(t_game *game);

#endif
