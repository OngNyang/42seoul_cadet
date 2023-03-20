#include "minitalk.h"

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);	//프로세스 아이디가 pid인 프로세스에 SIGUSR1신호를 보낸다.
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc ==3)
	{
		pid = ft_atoi(argv[1]); 	//문자열인 pid를 정수로 바꿔 저장.
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i]);	//보내는 문자열의 각 문자마다 ft_send_bits()함수에 넣어줌
			i++;
		}
		ft_send_bits(pid, '\n');	// 마지막 개행
	}
	else
	{
		// ft_printf("Error: wrong format\n");
		ft_putstr_fd("Error: wrong format\n", 2);
		return (1);	//에러 발생시 non-zero 반환
	}
	return (0);
}