/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:43:41 by hyejeong          #+#    #+#             */
/*   Updated: 2023/02/28 01:43:45 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, j * XPM_BIT, i * XPM_BIT);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.collectible, j * XPM_BIT, i * XPM_BIT);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.background, j * XPM_BIT, i * XPM_BIT);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, j * XPM_BIT, i * XPM_BIT);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, j * XPM_BIT, i * XPM_BIT);
}

void	render_img(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			draw_img(game, i, j);
			j++;
		}
		i++;
	}
}