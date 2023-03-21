#incldue "minitalk.h"

int	main(int argc, char **argv)
{
	//인자 1개 아니면 에러

	//pid 얻기

	//pid를 포함한 것들 출력해기

	//무한루프로 신호 기다림
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0)

}