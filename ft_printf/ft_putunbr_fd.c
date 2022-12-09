/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:43:11 by hyejeong          #+#    #+#             */
/*   Updated: 2022/12/09 16:02:17 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printing(unsigned int num, int fd)
{
	unsigned int	base_n;

	base_n = 10;
	if (num >= base_n)
	{
		printing((num / base_n), fd);
		printing((num % base_n), fd);
	}
	else
		ft_putchar_fd('0' + num, fd);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int				res;
	unsigned int	base_n;

	base_n = 10;
	printing(n, fd);
	res = 0;
	while (n != 0)
	{
		n /= base_n;
		res++;
	}
	if (res == 0)
		res = 1;
	return (res);
}
