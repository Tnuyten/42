#include "../cub3d.h"

// int	get_tex_color(mlx_texture_t *tex, struct s_coord *pos)
// {
// 	if (pos->x >= 0 && pos->x < tex->width
// 		&& pos->y >= 0 && pos->y < tex->height)
// 	{
// 		return (*(int*)(tex->pixels + (4 * tex->width * (int)pos->y) + (4 * (int)pos->x)));
// 	}
// 	return (0x0);
// }
int	get_tex_color(mlx_texture_t *tex, struct s_coord *pos)
{
	uint32_t	subscr;
	uint32_t	*nt;
	uint32_t	color;

	subscr = (pos->y * tex->width + pos->x) * sizeof(int32_t);
	nt = (uint32_t*)&tex->pixels[subscr];
	color = *nt;
	// if (endianness)
	// 	color = ntohl(*nt);
	return (color);
}

// int	get_tex_color(mlx_texture_t *tex, struct s_coord *pos)
// {
//     char *dst;
 
// 	dst = tex->pixels + (pos->y * tex->width + pos->x * (tex->bytes_per_pixel / 8));

// 	return *dst;
// }

mlx_image_t	*texture_pixels(t_game *game)
{

    struct s_coord pos;
    pos.x = 0;
    pos.y = 0;
	
	// int x = 0;
	// int y = 0;
	mlx_texture_t	*tex = mlx_load_png("./img/mario.png");

	while (pos.y < game->map.east->height)
    {
	    while (pos.x < game->map.east->width)
        {
	        // mlx_put_pixel(game->background, pos.x, pos.y, get_tex_color(game->map.west, &pos));
	        mlx_put_pixel(game->background, pos.x, pos.y, get_tex_color(tex, &pos));
            pos.x++;
        }
        pos.y++;
    }
    return (game->background);
}

// static void
// 	draw_sprite_pixel(t_game *game, t_sprite *sprite, t_sprite_draw *spr,
// 		t_tex *tex)
// {
// 	t_pos	pixel;
// 	t_pos	tex_pos;
// 	int		color;

// 	set_pos(&pixel, spr->draw_x.x, spr->draw_y.x);
// 	if (set_tex_pos(game, spr, tex, &tex_pos))
// 	{
// 		color = shade_color(get_tex_color(tex, &tex_pos),
// 			(game->options & FLAG_SHADOWS) ? sprite->distance / 3 : 1);
// 		if (color != 0x0)
// 			draw_pixel(&game->window, &pixel, color);
// 	}
// }
