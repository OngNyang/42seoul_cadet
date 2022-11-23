/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:54:32 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/23 13:07:33 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = (long long)n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	else
	{
		if (num / 10 == 0)
		{
			n = n + '0';
			ft_putchar_fd(n, fd);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
