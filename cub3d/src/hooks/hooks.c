#include "hooks.h"

void	hooks(t_game *game)
{
	mlx_key_hook(game->mlx, movement_hooks, game);
}
