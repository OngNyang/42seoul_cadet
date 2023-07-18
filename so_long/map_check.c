/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:38:58 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/07 11:30:31 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_extension(char *filename)
{
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4) != 0)
		p_error("Wrong extension.\n");
}

void	check_map_rect(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height - 1)
	{
		if (game->width != ft_strlen(game->map[i]) - 1)
			p_error("map is not rectangular.\n");
		i++;
	}
}

void	check_map_wall(t_game *game)
{
	int	i_heightght;
	int	i_widthth;

	i_widthth = 0;
	while (i_widthth < game->width)
	{
		if (game->map[0][i_widthth] != '1')
			p_error("inappropriate wall.\n");
		if (game->map[game->height - 1][i_widthth] != '1')
			p_error("inappropriate wall.\n");
		i_widthth++;
	}
	i_heightght = 0;
	while (i_heightght < game->height)
	{
		if (game->map[i_heightght][0] != '1')
			p_error("inappropriate wall.\n");
		if (game->map[i_heightght][game->width - 1] != '1')
			p_error("inappropriate wall.\n");
		i_heightght++;
	}
}

void	check_map_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' \
			&& game->map[i][j] != 'C' && game->map[i][j] != 'P' \
			&& game->map[i][j] != 'E')
				p_error("Wrong character\n");
			j++;
		}
		i++;
	}
}

void	check_map_components(t_game *game)
{
	int	i;
	int	j;
	int	num_exit;
	int	num_player;

	num_player = 0;
	num_exit = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				game->total_coll++;
			if (game->map[i][j] == 'E')
				num_exit++;
			if (game->map[i][j] == 'P')
				num_player++;
			j++;
		}
		i++;
	}
	if ((num_exit != 1) || (num_player != 1) || (game->total_coll < 1))
		p_error("wrong components.\n");
}
