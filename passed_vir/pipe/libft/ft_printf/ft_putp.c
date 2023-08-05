/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:43:03 by hyejeong          #+#    #+#             */
/*   Updated: 2023/01/04 16:10:44 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printing(size_t n)
{
	if (n < 16)
	{
		ft_putchar("0123456789abcdef"[n % 16], 1);
	}
	else
	{
		printing(n / 16);
		printing(n % 16);
	}
}

int	ft_putp(void *ptr)
{
	size_t	n;
	int		res;

	res = 0;
	n = (size_t)ptr;
	res += ft_putstr("0x", 1);
	printing(n);
	while (n != 0)
	{
		n /= 16;
		res++;
	}
	if (ptr == NULL)
		res = 3;
	return (res);
}
//receive address.
//print hexa address