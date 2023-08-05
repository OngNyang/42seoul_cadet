/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:10:28 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/03 14:22:43 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	aaa;

	aaa = '0';
	while (1)
	{
		write(1, &aaa, 1);
		if (aaa == '9')
		{
			break ;
		}
		aaa++;
	}
}
