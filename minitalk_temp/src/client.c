#include "../inc/minitalk.h"


// void	ft_send_bits(int pid, char c)
// {
// 	int	i;
// 	int	filter;

// 	filter = 1;
// 	i = 0;
// 	while (i < 8)
// 	{
// 		if ((filter & c) == 0)
// 			kill(pid, SIGUSR2);
// 		else
// 			kill(pid, SIGUSR1);
// 		usleep(30);
// 		i++;
// 		filter *= 2;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int	pid;
// 	int	i;
// 	//argc는 3이어야만 함
// 	if (argc != 3)
// 	{
// 		ft_putstr_fd("Error: wrong arguments.\n1. PID\n2. string\n", 2);
// 		exit(1);
// 	}
// 	pid = ft_atoi(argv[1]);
// 	i = 0;
// 	while (argv[2][i])
// 	{
// 		ft_send_bits(pid, argv[2][i]);
// 		i++;
// 	}
// 	ft_send_bits(pid, '\n');
// 	return (0);
// }


//----------------------------



// void	ft_send_bits(int pid, char i)
// {
// 	int	bit;

// 	bit = 0;
// 	while (bit < 8)
// 	{
// 		if ((i & (0x01 << bit)) != 0)
// 			kill(pid, SIGUSR1);	//프로세스 아이디가 pid인 프로세스에 SIGUSR1신호를 보낸다.
// 		else
// 			kill(pid, SIGUSR2);
// 		usleep(100);
// 		bit++;
// 	}
// }

// int main(int argc, char **argv)
// {
// 	int	pid;
// 	int	i;

// 	i = 0;
// 	if (argc ==3)
// 	{
// 		pid = ft_atoi(argv[1]); 	//문자열인 pid를 정수로 바꿔 저장.
// 		while (argv[2][i] != '\0')
// 		{
// 			ft_send_bits(pid, argv[2][i]);	//보내는 문자열의 각 문자마다 ft_send_bits()함수에 넣어줌
// 			i++;
// 		}
// 		ft_send_bits(pid, '\n');	// 마지막 개행
// 	}
// 	else
// 	{
// 		// ft_printf("Error: wrong format\n");
// 		ft_putstr_fd("Error: wrong arguments.\n1. PID\n2. string\n", 2);
// 		return (1);	//에러 발생시 non-zero 반환
// 	}
// 	return (0);
// }





void	send_sig(int pid, char *str, int length)
{
	int	byte_index;		//바이트당 처리를 위한 변수
	int	bit_index;		//비트당 처리를 위한 변수
	int	bit_temp;		//0과 1을 처리하기 위한 변수

	byte_index = 0;		//바이트 인덱스 0으로 초기화
	while (byte_index < length)	//글자를 모두 server로 보내기 위한 while
	{
		bit_index = 0;	//비트 인덱스 문자열 전체 끝날때까지 0으로 초기화
		while (bit_index < 8)	//1바이트는 8비트이므로 0~7까지 동작
		{
			bit_temp = str[byte_index] >> (7 - bit_index) & 1;	//앞에서부터 보내줘야하므로 우측으로 비트 연산 후 bit_temp에 0과 1 중 한 값을 담는다.	비트 연산 추후 아래에서 기술 예정.
			if (bit_temp == 0)
				kill(pid, SIGUSR1);	//kill 함수를 통해 SIGUSR1 server로 전달 (server에서 SIGUSR1을 받으면 0으로 변환할 것임)
			else if (bit_temp == 1)
				kill(pid, SIGUSR2); //kill 함수를 통해 SIGUSR2 server로 전달 (server에서 SIGUSR2을 받으면 1으로 변환할 것임)
			usleep(30);	//kill 함수를 통해 서버에게 일방적으로 반복적인 신호를 전송할 것이기 때문에 약간의 딜레이가 필요하다.
			bit_index++;
		}
		byte_index++;
	}
}

void	get_str(int pid, char *str)
{
	int		length;
	char	*send;

	send = ft_strjoin(str, "\n");	//마지막에 줄바꿈을 추가해준다.
	if (send == NULL)	//ft_strjoin 실패시 에러처리
		exit(1);
	length = ft_strlen(send);	//길이를 재고
	send_sig(pid, send, length);	//해당 값들을 인자로 새 함수에 넘겨준다.
	free(send);
	exit(0);
}

int	main(int ac, char *av[])
{
	pid_t	pid;	//pid_t 자료형은 pid를 저장할 수 있는 타입인 자료형이다.

	if (ac != 3)	//에러처리
	{
		// ft_printf("Arguement is Wrong!!\n");
		exit(1);
	}
	pid = ft_atoi(av[1]); //문자열로 받은 server의 pid 숫자로 변환
	if (pid < 100 || pid > 99998) //가능한 pid의 범위이다. 100 이하는 시스템 프로세스, 99999 이상은 맥 환경에서 존재할 수 없는 pid이므로 예외처리를 해준다.
	{
		// ft_printf("Invalid PID...\n");
		exit(1);
	}
	get_str(pid, av[2]);
}