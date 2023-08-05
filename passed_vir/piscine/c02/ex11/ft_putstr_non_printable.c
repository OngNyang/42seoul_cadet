/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:23:10 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/09 23:31:38 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexa(unsigned char c)
{
	int		n1;
	int		n2;
	char	c1;
	char	c2;

	n1 = c / 16;
	c1 = "0123456789abcdef"[n1];
	n2 = c % 16;
	c2 = "0123456789abcdef"[n2];
	write(1, "\\", 1);
	write(1, &c1, 1);
	write(1, &c2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*temp;

	temp = (unsigned char *)str;
	while (*temp != '\0')
	{
		if (*temp < 32 || *temp >= 127)
		{
			hexa(*temp);
			temp++;
		}
		else
		{
			write(1, temp, 1);
			temp++;
		}
	}
}
