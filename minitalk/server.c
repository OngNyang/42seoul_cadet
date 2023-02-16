#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
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