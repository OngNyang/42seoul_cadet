/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:51:45 by hyejeong          #+#    #+#             */
/*   Updated: 2023/02/28 04:53:04 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc_game(t_game *game)
{
	int	i;

	mlx_destroy_window(game->mlx, game->win);
	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	exit(1);
}

void	print_error(char *message, t_game *game)
{
	write(2, "Error: ", 7);
	ft_putstr_fd(message, 2);
	esc_game(game);
}

void	p_error(char *message)
{
	write(2, "Error: ", 7);
	ft_putstr_fd(message, 2);
	exit(1);
}