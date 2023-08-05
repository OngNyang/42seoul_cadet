/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:25:10 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/11 20:09:15 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_discriminant(char *base)
{
	int	i;
	int	j;
	int	base_len;

	base_len = 0;
	while (*(base + base_len) != '\0')
		base_len++;
	if (base_len <= 1)
		return (0);
	i = 0;
	while (*(base + i) != '\0')
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	base_trsf(unsigned int nbr, unsigned int base_len, char *base)
{
	if (nbr / base_len == 0)
	{
		write (1, &base[nbr % base_len], 1);
		return ;
	}
	else if (nbr / base_len != 0)
	{
		base_trsf(nbr / base_len, base_len, base);
		write(1, &base[nbr % base_len], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;

	if (base_discriminant(base) == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = (unsigned int)(-1 * nbr);
	}
	else
		nbr = (unsigned int)(1 * nbr);
	base_len = 0;
	while (*(base + base_len) != '\0')
		base_len++;
	base_trsf(nbr, base_len, base);
}
