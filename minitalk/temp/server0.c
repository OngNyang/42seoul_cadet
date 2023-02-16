/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:10:43 by hyejeong          #+#    #+#             */
/*   Updated: 2023/02/16 16:57:59 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_talk(int signal)
{
	static char	bit;	 //char vs int 고민	아 근데 일단 보내는거는 정수가 아니라 문자를 계속 보내는것이니 숫자를 보내는것도 char 해도 되고 인덱스 한계를 8로 해도 될듯
	static int	bit_index;

	if (signal == SIGUSR1)	//비트가 1인경우
		bit = bit | (1 << bit_index);
	else if (signal == SIGUSR2)
		bit = bit | (0 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", bit);	 // 일단은 static char 이니까 %c로 했음
		bit = 0;
		bit_index = 0;
	}
}

int main(int argc, char **argv)
{
	int	pid;

	if (argc != 1)
		return (1);
	(void)argv;
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, ft_talk);
		signal(SIGUSR2, ft_talk);
		pause();
	}
	return (0);
}