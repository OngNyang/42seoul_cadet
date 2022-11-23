/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:31:13 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/23 13:38:31 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long long	sign;
	int			i;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	if (*nptr == '\0')
		return (0);
	if (*nptr == '-')
		sign = -1;
	while (*(nptr + i) != '\0')
	{
		if (*(nptr + i) >= '0' && *(nptr + i) <= '9')
		{
			res = res * 10 + *(nptr + i) - '0';
		}
		else
		{
			break ;
		}
		i++;
	}
	res = sign * res;
	return ((int)res);
}
