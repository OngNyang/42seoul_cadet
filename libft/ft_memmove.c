/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:36:18 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/22 12:57:35 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*temp_d;
	const unsigned char	*temp_s;

	temp_d = (unsigned char *)dst;
	temp_s = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (dst);
	if (src > dst)
	{
		while (len--)
			*temp_d++ = *temp_s++;
	}
	else
	{
		while (len--)
		{
			*(temp_d + len) = *(temp_s + len);
		}
	}
}
