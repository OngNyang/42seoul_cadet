#include "so_long.h"
#include <stdio.h>

// void	print_error(char *message)
// {
// 	write(2, "Error: ", 7);
// 	// write(2, message, ft_strlen(message));
// 	ft_putstr_fd(message, 2);
// 	exit(1);
// }
//------------------------------

void	game_over(t_game *game)
{
	game->num_step++;
	ft_putnbr_fd(game->num_step, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("mission complete!", 1);
	exit(0);
}


int	current_position(t_game *game, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				if (c == 'i')
					return (i);
				if (c == 'j')
					return (j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

t_vector	c_p(t_game *game)
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

t_vector new_c_p(t_vector vect, int key_code)
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

void	move_player(t_game *game, int key_code)
{
	t_vector	vect;
	t_vector	new_vect;
	
	vect = c_p(game);
	new_vect = new_c_p(vect, key_code);
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
	// setting_img(game);
}

void	move_w(t_game *game)
{
/*
일단 p의 위치를 찾기.
이동 가능한 경우
1. 자유지
2. 수집품
3. 수집품을 다먹은 상태에서 출구
	현위치 0으로 만들기
	이동할 위치 P로 만들기.
*/
	int	i;
	int	j;

	i = current_position(game, 'i');
	j = current_position(game, 'j');
	if ((game->map[i - 1][j] == '1') || ((game->map[i - 1][j] == 'E') && (game->total_coll != game->num_coll)))
		return ;
	if (game->map[i - 1][j] == 'C')
		game->num_coll++;
	else if (game->map[i - 1][j] == 'E')
		game_over(game);
	game->map[i][j] = '0';
	game->map[i - 1][j] = 'P';
	game->num_step++;
	ft_putnbr_fd(game->num_step, 1);
	ft_putchar_fd('\n', 1);
	// setting_img(game);
}

void	move_a(t_game *game)
{
	int	i;
	int	j;

	i = current_position(game, 'i');
	j = current_position(game, 'j');
	if ((game->map[i][j - 1] == '1') || ((game->map[i][j - 1] == 'E') && (game->total_coll != game->num_coll)))
		return ;
	if (game->map[i][j - 1] == 'C')
		game->num_coll++;
	else if (game->map[i][j - 1] == 'E')
		game_over(game);
	game->map[i][j] = '0';
	game->map[i][j - 1] = 'P';
	game->num_step++;
	ft_putnbr_fd(game->num_step, 1);
	ft_putchar_fd('\n', 1);
	// setting_img(game);
}

void	move_s(t_game *game)
{
	int	i;
	int	j;

	i = current_position(game, 'i');
	j = current_position(game, 'j');
	if ((game->map[i + 1][j] == '1') || ((game->map[i + 1][j] == 'E') && (game->total_coll != game->num_coll)))
		return ;
	if (game->map[i + 1][j] == 'C')
		game->num_coll++;
	else if (game->map[i + 1][j] == 'E')
		game_over(game);
	game->map[i][j] = '0';
	game->map[i + 1][j] = 'P';
	game->num_step++;
	ft_putnbr_fd(game->num_step, 1);
	ft_putchar_fd('\n', 1);
	// setting_img(game);
}

void	move_d(t_game *game)
{
	int	i;
	int	j;

	i = current_position(game, 'i');
	j = current_position(game, 'j');
	if ((game->map[i][j + 1] == '1') || ((game->map[i][j + 1] == 'E') && (game->total_coll != game->num_coll)))
		return ;
	if (game->map[i][j + 1] == 'C')
		game->num_coll++;
	else if (game->map[i][j + 1] == 'E')
		game_over(game);
	game->map[i][j] = '0';
	game->map[i][j + 1] = 'P';
	game->num_step++;
	ft_putnbr_fd(game->num_step, 1);
	ft_putchar_fd('\n', 1);
	// setting_img(game);
}


//-------------------------------------
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
		print_error("wrong components.\n", game);
}

void	check_map_wall(t_game *game)
{
	int	i_heightght;
	int	i_widthth;

	i_widthth = 0;
	while (i_widthth < game->width)
	{
		if (game->map[0][i_widthth] != '1')
			print_error("inappropriate wall.\n", game);
		if (game->map[game->height - 1][i_widthth] != '1')
			print_error("inappropriate wall.\n", game);
		i_widthth++;
	}
	i_heightght = 0;
	while (i_heightght < game->height)
	{
		if(game->map[i_heightght][0] != '1')
			print_error("inappropriate wall.\n", game);
		if(game->map[i_heightght][game->width - 1] != '1')
			print_error("inappropriate wall.\n", game);
		i_heightght++;
	}
}

void	check_map_rect(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height - 1)
	{
		if (game->width != ft_strlen(game->map[i]) - 1)
			print_error("map is not rectangular.\n", game);
		i++;
	}
}

void	check_map(t_game *game)
{
	/*
	1. 직사각형인지.
	2. 벽으로 둘러쌓인 맵인지.
	3. 각 요소의 갯수가 적절한지.
	4. 유효경로 확인.
	5. 확장자 .ber확인				//메인문에서 해결
	*/
	check_map_rect(game);
	check_map_wall(game);
	check_map_components(game);

}

//------------------------------

int	cnt_line(char *filename, t_game *game)
{
	int		fd;
	int		line_num;
	int		read_len;
	char	c;

	line_num = 1;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_error("fail to open file.\n", game);
	while (1)
	{
		read_len = read(fd, &c, 1);
		if (read_len < 0)
			print_error("fail to get map-heightght", game);
		if (read_len == 0)
			break ;
		if (c == '\n')
			line_num++;
	}
	close(fd);
	if (line_num <= 2)	//2주이면 벽만 만들어야 하기에 부적절
		print_error("map is inappropriate.\n", game);
	return (line_num);
}

void	initializing(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->total_coll = 0;
	game->num_coll = 0;
	game->num_step = 0;
}


void	map_read(char *filename, t_game *game)
{
	/*
	1. 높이 재기
	2. 너비 재기
	3. 맵 읽어와서 1줄로 저장 그냥 2차원 배열로 만들까...
	4. 걸음수 0으로 초기화
	*/

	int		fd;
	int		i;
	
	initializing(game);
	game->height = cnt_line(filename, game);
	game->map = malloc(sizeof(char*) * (game->height + 1));
	if (!game->map)
		print_error("malloc() fail.\n", game);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	game->width = ft_strlen(game->map[i - 1]);	//\n 빼고 재야 하는데 마지막은 개행 없징
	// game->num_step = 0;	//얘랑 위에거 따로 함수 만들고 싶음.
	close(fd);
}
//개행 있게 만들어 버림. 개행 없는 2차원 배열이 더 좋지 않낭?


int	main(int argc, char **argv)
{
	int		i;
	t_game	*game;

	game = malloc(sizeof(t_game) * 1);
	map_read(argv[1], game);

	check_map(game);
	
	// move_w(game);
	// move_w(game);
	// move_w(game);
	// move_a(game);
	// move_s(game);
	// move_d(game);

	move_player(game, KEY_W);
	move_player(game, KEY_W);
	move_player(game, KEY_W);
	move_player(game, KEY_A);
	move_player(game, KEY_S);
	move_player(game, KEY_D);

	if (argc != 2)
		return (1);
	i = 0;
	while (game->map[i] != NULL)
	{
		printf("%s\n",game->map[i]);
		i++;
	}
	return (0);
}






// void	map_read(char *filename, t_game *game)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		print_error("fail to read map from file.\n");
// 	game->height = -1;
// 	game->str_line = NULL;
// 	line = ft_strdup("");
// 	while (line)
// 	{
// 		game->height++;
// 		line = get_next_line(fd);
// 		if (line)
// 		{
// 			if (!game->str_line)
// 			{
// 				game->str_line = ft_strdup("");
// 			}
// 			game->str_line = ft_strjoin_without_newline(game->str_line, line);
// 		}
// 	}
// 	close(fd);
// 	game->width = ft_strlen(game->str_line) / game->height;
// 	ft_putnbr_fd(ft_strlen(game->str_line), 1);
// 	ft_putnbr_fd(game->height, 1);
// 	ft_putnbr_fd(game->width, 1);
// }