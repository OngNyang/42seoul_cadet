/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:33:06 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/11 20:06:13 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	cnt;
	int	res;

	cnt = 1;
	res = 0;
	while (*str != '\0')
	{
		while (*str == 32 || (9 <= *str && *str <= 13))
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				cnt *= -1;
			str++;
		}
		while ('0' <= *str && *str <= '9')
		{
			res = (10 * res) + *str - '0';
			str++;
		}
		return (cnt * res);
	}
	return (0);
}
