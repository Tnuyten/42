/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:20:36 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/20 17:52:06 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	leaks(void)
{
	system("leaks cub3d");
	system("lsof -c cub3d");
}

void	check_args(t_game *game, int argc, char **argv)
{
	char	*cub_pos;
	int		fd;

	if (argc != 2)
		clear_and_exit(game, EXIT_FAILURE, "Usage: ./cub3d [map_name].cub");
	cub_pos = argv[1] + ft_strlen(argv[1]) - 4;
	if (ft_strnstr(cub_pos, ".cub", 4) == NULL)
		clear_and_exit(game, EXIT_FAILURE, "Argument is not a .cub file");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		clear_and_exit(game, EXIT_FAILURE, "Could not open map file");
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	game.map = ft_calloc(1, sizeof(t_map));
	game.minimap_enabled = true;
	if (game.map == NULL)
		clear_and_exit(&game, EXIT_FAILURE, "Allocation error");
	check_args(&game, argc, argv);
	if (parse_map(argv[1], game.map) == -1)
		clear_and_exit(&game, EXIT_FAILURE, "Parse error");
	if (validate(game.map) == false)
		clear_and_exit(&game, EXIT_FAILURE, "Map is not valid");
	init(&game);
	make_minimap(&game);
	draw_screen(&game);
	mlx_image_to_window(game.mlx, game.screen, 0, 0);
	hooks(&game);
	mlx_loop(game.mlx);
}
