#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	bit;	//신호가 들어올때마다 함수가 재호출 되야하고, 비트가 8개 다 채워질때까지 변수의 값이 유지 되어야 한다.
	static int	i;		//따라서 정적변수 사용이 필요하다

	if (signal == SIGUSR1)	//신호가 1인경우 비트 연산을 한다. 0인경우는 할필요가 없다.
		i |= (1 << bit);
	bit++;
	if (bit == 8)	//char타입인 1바이트 즉, 8비트가 다 차면 
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format\n");
		return (1);
	}
	pid = getpid();
	if (!(2 <= pid && pid <= 32768))	//pid번호가 잘못된 경우
	{
		ft_printf("Errot: invalid PID\n");
		return (1);
	}
	ft_printf("PID : %d\n", pid);
	ft_printf("Waiting for a message...\n");
	while(1)
	{
		signal(SIGUSR1, ft_handler); //SIGUSR1 신호를 기다리다, 신호가 들어오면 함수를 실행시켜줌
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}