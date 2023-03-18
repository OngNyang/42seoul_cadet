/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:40:07 by hyejeong          #+#    #+#             */
/*   Updated: 2023/02/24 00:09:44 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_strlen(const char *str)
{
	long long	i;

	if (!str)
		return (0);
	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}
