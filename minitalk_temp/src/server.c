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
		// ft_printf("%c", i);
		ft_putchar_fd(i, 1);
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
		// ft_printf("Error: wrong format\n");
		ft_putstr_fd("Error: wrong format\n", 2);
		return (1);
	}
	pid = getpid();
	// ft_printf("PID : %d\n", pid);
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Waiting for a message...\n", 1);
	// ft_printf("Waiting for a message...\n");
	while(1)
	{
		signal(SIGUSR1, ft_handler); //SIGUSR1 신호를 기다리다, 신호가 들어오면 함수를 실행시켜줌
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}