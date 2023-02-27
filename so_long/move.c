#include "so_long.h"

t_vector	current_position(t_game *game)
{
	t_vector	vect;

	vect.i = 0;
	while (vect.i < game->height)
	{
		vect.j = 0;
		while (vect.j < game->width)
		{
			if (game->map[vect.i][vect.j] == 'P')
			{
				return (vect);
			}
			vect.j++;
		}
		vect.i++;
	}
	return (vect);
}

t_vector	new_position(t_vector vect, int key_code)
{
	t_vector	new_vect;

	new_vect.i = -1;
	new_vect.j = -1;
	if (key_code == KEY_A)
		new_vect.j = vect.j - 1;
	else if (key_code == KEY_S)
		new_vect.i = vect.i + 1;
	else if (key_code == KEY_D)
		new_vect.j = vect.j + 1;
	else if (key_code == KEY_W)
		new_vect.i = vect.i - 1;
	if (new_vect.i == -1)
		new_vect.i = vect.i;
	if (new_vect.j == -1)
		new_vect.j = vect.j;
	return (new_vect);
}

void	game_over(t_game *game)
{
	game->num_step++;
	ft_putnbr_fd(game->num_step, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("mission complete!\n", 1);
	esc_game(game);
}

void	move_player(t_game *game, int key_code)
{
	t_vector	vect;
	t_vector	new_vect;
	
	vect = current_position(game);
	new_vect = new_position(vect, key_code);
	if ((game->map[new_vect.i][new_vect.j] == '1') || ((game->map[new_vect.i][new_vect.j] == 'E') && (game->total_coll != game->num_coll)))
		return ;
	if (game->map[new_vect.i][new_vect.j] == 'C')
		game->num_coll++;
	else if (game->map[new_vect.i][new_vect.j] == 'E')
		game_over(game);
	game->map[vect.i][vect.j] = '0';
	game->map[new_vect.i][new_vect.j] = 'P';
	game->num_step++;
	ft_putnbr_fd(game->num_step, 1);
	ft_putchar_fd('\n', 1);
	render_img(game);
}

int	hook_key_press(int key_code, t_game *game)
{
	if (key_code == KEY_A)
		move_player(game, KEY_A);
	else if (key_code == KEY_S)
		move_player(game, KEY_S);
	else if (key_code == KEY_D)
		move_player(game, KEY_D);
	else if (key_code == KEY_W)
		move_player(game, KEY_W);
	else if (key_code == KEY_ESC)
		esc_game(game);
	return (0);
}

