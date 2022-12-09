/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:22:12 by hyejeong          #+#    #+#             */
/*   Updated: 2022/12/09 15:41:26 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			printing(long long num, int fd, char base);
static long long	check_nbr(long long num, int fd, int *base_n);
int					ft_putnbr_base_fd(int n, int fd, char base);


static long long	check_nbr(long long num, int fd, int *base_n)
{
	*base_n = 16;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
		//printing(num, fd, base);
	}
	return (num);
}
//check base where number is printed.

static void	printing(long long num, int fd, char base)
{
	int	base_n;

	num = check_nbr(num, fd, &base_n);
	if (num >= base_n)
	{
		printing((int)(num / base_n), fd, base);
		printing((int)(num % base_n), fd, base);
	}
	else 
	{
		if (num >= 10 && base == 'X')
			ft_putchar_fd('A' + num - 10, fd);
		else if (num >= 10 && base == 'x')
			ft_putchar_fd('a' + num - 10, fd);
		else
			ft_putchar_fd('0' + num, fd);
	}
}
//divide. get remainder and share. print 

int	ft_puthexnbr_fd(long long num, int fd, char base)
{
	int			res;
	int			base_n;

	base_n = 16;
	printing(num, fd, base);
	res = 0;
	if (num < 0)
	{
		num *= -1;
		res++;
	}
	while (num != 0)
	{
		num /= base_n;
		res++;
	}
	if (res == 0)
		res = 1;
	return (res);
}
//ft_putnbr_base_fd -> count letters which is printed.