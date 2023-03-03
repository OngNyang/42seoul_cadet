/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:12:53 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/03 15:13:02 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>

# define XPM_BIT		64

# define KEY_PRESS		2
# define DESTROY_NOTIFY	17

# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13
# define KEY_ESC		53

typedef struct s_vector
{
	int	i;
	int	j;
}				t_vector;

typedef struct s_img
{
	void	*player;
	void	*collectible;
	void	*background;
	void	*exit;
	void	*wall;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		width;
	int		height;
	int		total_coll;
	int		num_coll;
	int		num_step;
	char	**map;
}				t_game;

/*
errors.c
*/
int		esc_game(t_game *game);
void	print_error(char *message, t_game *game);
void	p_error(char *message);

/*
image.c
*/
void	render_img(t_game *game);
void	draw_img(t_game *game, int i, int j);

/*
init.c
*/
void	init_map(t_game *game, char *filename);
t_img	init_img(void *mlx);
void	init_s_game(t_game *game);
void	init_game(t_game *game, char *filename);

/*
map.c
*/
int		cnt_line(char *filename);
void	gnl_ber_to_array(char*filename, t_game *game);

/*
map_check.c
*/
void	check_map_extension(char *filename);
void	check_map_rect(t_game *game);
void	check_map_wall(t_game *game);
void	check_map_components(t_game *game);

/*
map_valid_path.c
*/
int			contrast(t_game *game, int **visited);
void		dfs(t_game *game, int **visited, int current_i, int current_j);
int			valid_path(t_game *game);
t_vector	start_pos(t_game *game);

/*
move.c
*/
t_vector	current_position(t_game *game);
t_vector	new_position(t_vector vect, int key_code);
void		game_over(t_game *game);
void		move_player(t_game *game, int key_code);
int			hook_key_press(int key_code, t_game *game);


#endif