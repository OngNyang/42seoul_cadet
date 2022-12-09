/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:42:58 by hyejeong          #+#    #+#             */
/*   Updated: 2022/12/09 16:01:23 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			printing(long long num, int fd, char base);
static long long	check_nbr(long long num, int fd, char base, int *base_n);
int					ft_putnbr_base_fd(int n, int fd, char base);

static long long	check_nbr(long long num, int fd, char base, int *base_n)
{
	if (base == 'd' || base == 'i')
		*base_n = 10;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	return (num);
}
//check base where number is printed.

static void	printing(long long num, int fd, char base)
{
	int	base_n;

	num = check_nbr(num, fd, base, &base_n);
	if (num >= base_n)
	{
		printing((int)(num / base_n), fd, base);
		printing((int)(num % base_n), fd, base);
	}
	else
	{
		ft_putchar_fd('0' + num, fd);
	}
}
//divide. get remainder and share. print 

int	ft_putnbr_base_fd(int n, int fd, char base)
{
	int			res;
	int			base_n;
	long long	num;

	base_n = 10;
	num = (long long)n;
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