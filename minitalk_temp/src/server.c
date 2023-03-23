#include "../inc/minitalk.h"


// int	get_filter(int n)
// {
// 	int	i;
// 	int	res;

// 	res = 1;
// 	i = 0;
// 	while (i < n)
// 	{
// 		res *= 2;
// 		i++;
// 	}
// 	return (res);
// }

// void	ft_handler(int signal)
// {
// 	static int		i;
// 	static int		c;
// 	int			filter;

// 	filter = get_filter(i);
// 	if (signal == SIGUSR1)
// 		c += filter;
// 	i++;
// 	if (i == 8)
// 	{
// 		ft_putchar_fd(c, 1);
// 		i = 0;
// 		c = 0;
// 	}
// }


// int	main(int argc, char **argv)
// {
// 	int pid;

// 	(void)argv;
// 	if (argc != 1)
// 	{
// 		ft_putstr_fd("Error: wrong argument\n", 2);
// 		return (1);
// 	}
// 	pid = getpid();
// 	ft_putstr_fd("PID : ", 1);
// 	ft_putnbr_fd(pid, 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd("Waiting for a message...\n", 1);
// 	while(1)
// 	{
// 		signal(SIGUSR1, ft_handler); //SIGUSR1 신호를 기다리다, 신호가 들어오면 함수를 실행시켜줌
// 		signal(SIGUSR2, ft_handler);
// 		pause();
// 	}
// 	return (0);
// }

//-----------------------------


// void	ft_handler(int signal)
// {
// 	static int	bit;
// 	static int	i;

// 	if (signal == SIGUSR1)
// 		i |= (0x01 << bit);
// 	bit++;
// 	if (bit == 8)
// 	{
// 		// ft_printf("%c", i);
// 		ft_putchar_fd(i, 1);
// 		bit = 0;
// 		i = 0;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int pid;

// 	(void)argv;
// 	if (argc != 1)
// 	{
// 		// ft_printf("Error: wrong format\n");
// 		ft_putstr_fd("Error: wrong argument\n", 2);
// 		return (1);
// 	}
// 	pid = getpid();
// 	// ft_printf("PID : %d\n", pid);
// 	// ft_printf("Waiting for a message...\n");

// 	ft_putstr_fd("PID : ", 1);
// 	ft_putnbr_fd(pid, 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd("Waiting for a message...\n", 1);

// 	while(1)
// 	{
// 		signal(SIGUSR1, ft_handler); //SIGUSR1 신호를 기다리다, 신호가 들어오면 함수를 실행시켜줌
// 		signal(SIGUSR2, ft_handler);
// 		pause();
// 	}
// 	return (0);
// }




void	get_sig(int sig)
{
	static char	temp;
	static int	bit;	//1비트씩 받아서 받을때마다 get_sig함수가 출력되므로 계속 실행될 때 bit 값이 유지되도록 static 변수 선언

	if (sig == SIGUSR1)
	{
		temp |= 0;	//0과 or연산, client에서 보낼 때 SIGUSR1은 0을 kill로 보내줬으므로 0과 or연산해도 0이 temp에 담긴다.
		if (bit < 7)
			temp <<= 1;	//앞쪽부터 담아야 하므로 왼쪽으로 1칸 시프트 연산
	}
	else if (sig == SIGUSR2)
	{
		temp |= 1;	//1과 or연산 1과 1은 or연산해도 1
		if (bit < 7)
			temp <<= 1;
	}
	bit++;	//비트 하나씩 증가하며 함수 계속 실행
	if (bit == 8)	//8비트, 즉 한 글자가 되면 출력후 비트와 템프 초기화
	{
		write(1, &temp, 1);
		bit = 0;
		temp = 0;
	}
}

int	main(void)
{
	// ft_printf("server pid : %d\n", getpid());	//처음 server의 pid 주소 출력

	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Waiting for a message...\n", 1);

	signal(SIGUSR1, get_sig);	//client에서 kill로 보낸 시그널을 처리하기 위한 시그널 함수, SIGUSR1을 받으면 handler인 get_sig 함수 동작.
	signal(SIGUSR2, get_sig);
	while (1)
		pause();	//pause()함수는 시그널을 수신할 때까지 대기 상태로 전환된다. 비트를 계속 받야하기 때문에 pause함수가 꼭 필요하다.
}