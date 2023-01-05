/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:22:12 by hyejeong          #+#    #+#             */
/*   Updated: 2023/01/04 16:10:35 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printing(unsigned int num, char base)
{
	if (num >= 16)
	{
		printing(num / 16, base);
		printing(num % 16, base);
	}
	else
	{
		if (num >= 10 && base == 'X')
			ft_putchar_fd('A' + num - 10, 1);
		else if (num >= 10 && base == 'x')
			ft_putchar_fd('a' + num - 10, 1);
		else
			ft_putchar_fd('0' + num, 1);
	}
}

int	ft_put_hex_nbr(unsigned int num, char base)
{
	int	res;

	printing(num, base);
	res = 0;
	while (num != 0)
	{
		num /= 16;
		res++;
	}
	if (res == 0)
		res = 1;
	return (res);
}
