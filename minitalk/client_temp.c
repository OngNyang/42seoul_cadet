#include "minitalk.h"

void	ft_kill(int pid, char i)
{
	int	bit;
	int	temp;

	bit = 0;
	while (bit < 8)
	{
		temp = i & (1 << bit);	//최후미 비트부터 0인지 1인지 판별한다.
		if (temp == 0)	//비트가 0이면 sigusr2 신호
			kill(pid, SIGUSR2);
		else	//비트가 1이면 sigusr1신호. 단 비트가 1이어도 그값은 1이 아니겠지.
			kill(pid, SIGUSR1);
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
		if (!(2 <= pid && pid <= 32768))	//pid번호가 잘못된 경우
		{
			ft_printf("Errot: invalid PID\n");
			return (1);
		}
		while (argv[2][i] != '\0')
		{
			ft_kill(pid, argv[2][i]);	//보내는 문자열의 각 문자마다 ft_send_bits()함수에 넣어줌
			i++;
		}
		ft_kill(pid, '\n');	// 마지막 개행
	}
	else
	{
		ft_printf("Error: wrong argument\n");
		return (1);	//에러 발생시 non-zero 반환
	}
	return (0);
}