/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:40:40 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/06 15:36:22 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	contrast(t_game *game, int **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
			{
				if (visited[i][j] == 0)
					return (-1);
			}
			if (game->map[i][j] == 'E')
			{
				if (!(visited[i + 1][j] == 1 || visited[i - 1][j] == 1 \
				|| visited[i][j + 1] == 1 || visited[i][j - 1] == 1))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	dfs(t_game *game, int **visited, int current_i, int current_j)
{
	visited[current_i][current_j] = 1;
	if (visited[current_i][current_j - 1] == 0 \
	&& game->map[current_i][current_j - 1] != '1' \
	&& game->map[current_i][current_j - 1] != 'E')
		dfs (game, visited, current_i, current_j - 1);
	if (visited[current_i + 1][current_j] == 0 \
	&& game->map[current_i + 1][current_j] != '1' \
	&& game->map[current_i + 1][current_j] != 'E')
		dfs (game, visited, current_i + 1, current_j);
	if (visited[current_i][current_j + 1] == 0 \
	&& game->map[current_i][current_j + 1] != '1' \
	&& game->map[current_i][current_j + 1] != 'E')
		dfs (game, visited, current_i, current_j + 1);
	if (visited[current_i - 1][current_j] == 0 \
	&& game->map[current_i - 1][current_j] != '1' \
	&& game->map[current_i - 1][current_j] != 'E')
		dfs (game, visited, current_i - 1, current_j);
}

t_vector	start_pos(t_game *game)
{
	int			i;
	int			j;
	t_vector	vect;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				vect.i = i;
				vect.j = j;
			}
			j++;
		}
		i++;
	}
	return (vect);
}

void	free_visited(int **visited, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	valid_path(t_game *game)
{
	t_vector	s_v;
	int			**visited;
	int			i;
	int			j;

	visited = malloc(sizeof(int *) * game->height);
	i = 0;
	while (i < game->height)
		visited[i++] = malloc(sizeof(int) * game->width);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	s_v = start_pos(game);
	dfs(game, visited, s_v.i, s_v.j);
	i = contrast(game, visited);
	free_visited(visited, game);
	return (i);
}
