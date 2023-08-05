/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:37:15 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/03 15:37:14 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cnt_line(char *filename)
{
	int		fd;
	int		line_num;
	int		read_len;
	char	c;

	line_num = 1;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		p_error("fail to open file.\n");
	while (1)
	{
		read_len = read(fd, &c, 1);
		if (read_len < 0)
			p_error("fail to get map-height");
		if (read_len == 0)
			break ;
		if (c == '\n')
			line_num++;
	}
	close(fd);
	if (line_num <= 2)
		p_error("map is inappropriate.\n");
	return (line_num);
}

void	gnl_ber_to_array(char*filename, t_game *game)
{
	int		fd;
	int		i;

	init_s_game(game);
	game->height = cnt_line(filename);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		p_error("malloc() fail.\n");
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	game->width = ft_strlen(game->map[i - 1]);
	close(fd);
}
