/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:59:01 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/03 18:34:37 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	digitcnt(int aaa)
{
	int	cnt;

	cnt = 0;
	if (aaa < 0)
		aaa *= -1;
	while (aaa != 0)
	{
		aaa = aaa / 10;
		cnt++;
	}
	return (cnt);
}

void	positive(int aaa, int digit)
{
	char	str[14];
	int		index;

	digit = digitcnt(aaa);
	index = digit - 1;
	while (1)
	{
		if (aaa / 10 == 0)
		{
			str[index] = (char)((aaa % 10) + 48);
			break ;
		}
		str[index] = (char)((aaa % 10) + 48);
		aaa = aaa / 10;
		index -= 1;
	}
	write(1, str, digit);
}

void	ft_putnbr(int aaa)
{
	int	digit;

	digit = digitcnt(aaa);
	if (aaa == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2147483648", 10);
		return ;
	}
	else if (aaa == 0)
	{
		write(1, "0", 1);
	}
	else if (aaa < 0)
	{
		write(1, "-", 1);
		positive(aaa * (-1), digit);
	}
	if (aaa >= 0)
		positive(aaa, digit);
}
