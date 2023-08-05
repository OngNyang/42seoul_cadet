/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:25:25 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/07 11:27:08 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game, char *filename)
{
	check_map_extension(filename);
	gnl_ber_to_array(filename, game);
	check_map_rect(game);
	check_map_wall(game);
	check_map_char(game);
	check_map_components(game);
	if (valid_path(game) < 0)
		p_error("Map does not have a valid path.\n");
}

t_img	init_img(void *mlx)
{
	t_img	img;
	int		width;
	int		height;

	img.player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", \
	&width, &height);
	img.collectible = mlx_xpm_file_to_image(mlx, "./images/collectible.xpm", \
	&width, &height);
	img.background = mlx_xpm_file_to_image(mlx, "./images/background.xpm", \
	&width, &height);
	img.exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", \
	&width, &height);
	img.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", \
	&width, &height);
	return (img);
}

void	init_s_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->total_coll = 0;
	game->num_coll = 0;
	game->num_step = 0;
}

void	init_game(t_game *game, char *filename)
{
	init_s_game(game);
	game->mlx = mlx_init();
	game->img = init_img(game->mlx);
	init_map(game, filename);
}
