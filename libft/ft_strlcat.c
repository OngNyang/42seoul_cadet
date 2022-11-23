/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:09:54 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/23 18:04:52 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len < size)
	{
		while (*dst != '\0')
			dst++;
		i = 0;
		while (*src != '\0' && i < size - d_len -1)
		{
			*(dst++) = *(src++);
			i++;
		}
		*dst = '\0';
		return (d_len + s_len);
	}
	else
		return (s_len + size);
}
//두 문자열을 이어 붙임