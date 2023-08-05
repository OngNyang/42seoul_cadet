/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:56:06 by hyejeong          #+#    #+#             */
/*   Updated: 2022/09/29 16:00:00 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	hm;

	hm = 'z';
	while (1)
	{
		write(1, &hm, 1);
		if (hm == 'a')
		{
			break ;
		}
		hm--;
	}
}
