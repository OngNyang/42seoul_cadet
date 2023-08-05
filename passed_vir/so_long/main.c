/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:15:19 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/07 10:45:55 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong argument.\n", 1);
		exit(1);
	}
	init_game(game, argv[1]);
	game->win = mlx_new_window(game->mlx, game->width * XPM_BIT, \
	game->height * XPM_BIT, "so_long");
	render_img(game);
	mlx_hook(game->win, KEY_PRESS, 0, &hook_key_press, game);
	mlx_hook(game->win, DESTROY_NOTIFY, 0, &esc_game, game);
	mlx_loop(game->mlx);
	free(game);
	return (0);
}
