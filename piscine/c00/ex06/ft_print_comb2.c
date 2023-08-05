/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:13:17 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/20 01:03:08 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	itoc(int aaa)
{
	char	str[3];

	str[1] = (char)((aaa % 10) + 48);
	str[0] = (char)((aaa / 10) + 48);
	write(1, str, 2);
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	n2 = 1;
	while (n1 <= 98)
	{
		while (n2 <= 99)
		{
			itoc(n1);
			write(1, " ", 1);
			itoc(n2);
			if (n1 == 98 && n2 == 99)
				return ;
			write(1, ", ", 2);
			n2 += 1;
		}
		n1 += 1;
		n2 = n1 + 1;
	}
}
// #include <stdio.h>
// #include <unistd.h>
// int main(void){
// 		printf("\n----ex06----\n");
// 	ft_print_comb2();
// 	printf("\n");
// }