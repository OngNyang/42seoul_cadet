/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:30:41 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/19 17:36:35 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	strle(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_putstr(char *str)
{
	int	len;

	len = strle(str);
	write(1, str, len);
}
