/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:40:34 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/29 23:39:54 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (start > s_len)
		s_len = 0;
	else
	{
		if (len > s_len - start)
			s_len = s_len - start;
		else
			s_len = len;
	}
	temp = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!temp)
		return (0);
	i = 0;
	while (i < s_len)
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
