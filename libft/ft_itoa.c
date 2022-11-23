/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:31:00 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/23 17:03:18 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long long num);
static void	fill_mem(char *res, int n);
char		*ft_itoa(int n);

static void	fill_mem(char *res, int n)
{
	long long	num;
	int			i;
	int			size;

	num = (long long)n;
	if (num < 0)
	{
		num *= -1;
		res[i] = '-';
		i++;
	}
	size = get_size(num);
	res[i + size] = '\0';
	while (num != 0)
	{
		res[i + size - 1] = num % 10;
		size--;
		num = num / 10;
	}
}

static int	get_size(long long num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long	num;
	long long	sign;
	char		*res;

	num = (long long)n;
	if (num < 0)
	{
		sign = -1;
		num *= -1;
		res = (char *)malloc(sizeof(char) * (get_size(num) + 2));
	}
	else
		res = (char *)malloc(sizeof(char) * (get_size(num) + 1));
	if (!res)
		return (0);
	fill_mem(res, n);
	return (res);
}
