#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;	//t_game의 변수가 아니라 포인터 변수를 선언했기에 이후 malloc해줘야함.

	game = malloc(sizeof(t_game));
	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong argument.\n", 1);
		exit(1);
	}
	init_game(game, argv[1]);	//게임 시작에 관한 설정.
	game->win = mlx_new_window(game->mlx, game->width * XPM_BIT, game->height * XPM_BIT, "so_long");
	render_img(game);
	mlx_hook(game->win, KEY_PRESS, 0, &hook_key_press, game);	//특정 이벤트를 기다린다. 이벤트 발생시, press_key함수를 실행. 그 함수의 파라미터로 game 보내줌
	mlx_hook(game->win, DESTROY_NOTIFY, 0, &esc_game, game);	//window포인터, 이벤트 번호, mask(0으로 유지), 호출할 함수, 그 함수의 파라미터
	mlx_loop(game->mlx);	//이벤트 입력을 기다림. 렌더링함. main에 넣고 main함수가 끝나지 않도록하면서 들어오는 이벤트를 잡아 지정한 hook대로 동작하게 한다. 
	free(game);
	return (0);
}

	// if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	// 	print_error("Wrong extension.\n", game);
