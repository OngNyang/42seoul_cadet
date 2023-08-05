/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:41:34 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/20 01:04:19 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	increasing(char *str)
{
	*(str + 2) = *(str + 1) + 1;
	while (*(str + 2) <= '9')
	{
		write(1, str, 3);
		if (*(str + 0) != '7' || *(str + 1) != '8' || *(str + 2) != '9')
		{
			write(1, ", ", 2);
		}
		*(str + 2) = *(str + 2) + 1;
	}
}

void	ft_print_comb(void)
{
	char	str[4];

	str[0] = '0';
	str[1] = '1';
	str[2] = '2';
	while (str[0] <= '7')
	{
		str[1] = str[0] + 1;
		while (str[1] >= str[0] && str[1] <= '8')
		{
			increasing(str);
			str[1]++;
		}
		str[0]++;
	}
}
// #include <stdio.h>
// int main(void)
// {
// 	printf("\n----ex05----\n");
// 	ft_print_comb();
// 	printf("\n");

// }