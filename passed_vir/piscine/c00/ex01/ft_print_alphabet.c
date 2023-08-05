/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:30:37 by hyejeong          #+#    #+#             */
/*   Updated: 2022/09/29 15:41:36 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	hm;

	hm = 'a';
	while (1)
	{
		write(1, &hm, 1);
		if (hm == 'z')
		{
			break ;
		}
		hm++;
	}
}
