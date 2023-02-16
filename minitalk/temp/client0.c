/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:58:16 by hyejeong          #+#    #+#             */
/*   Updated: 2023/02/16 16:58:20 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_kill(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (((c >> i) & 1) == 0)
			kill(pid, SIGUSR2);
		else if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		i++;
		usleep(100);
	}
}

int main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Error: Wrong Argument");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_kill(pid, argv[2][i]);
		i++;
	}
	ft_kill(pid, '\n');
	return (0);
}