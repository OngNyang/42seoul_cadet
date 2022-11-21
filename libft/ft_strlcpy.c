/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:39:57 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/21 11:39:58 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcpy(char *dst, const char *str, size_t size)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(str);
	if (!dst || !str)
		return (0);
	while (i < s_len && i < size - 1)
	{
		dst[i] = str[i];
		i++;
	}
	if (size > 0)
	{
		dst[i] = '\0';
	}
	return (s_len);
}
