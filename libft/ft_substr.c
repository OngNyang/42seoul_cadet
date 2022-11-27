/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:40:34 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/27 19:47:34 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*temp;
	unsigned int	s_len;
	unsigned int	i;

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
/*
주어진 문자열의 특정 인덱스(start)부터 특정 사이즈(len) 만큼의 문자들을 동적할당된 메모리에 저장합니다.
주의할점은 메모리 낭비를 방지하기 위해 여러가지 케이스로 나누어 메모리 할당량을 정확히 계산해 내는것입니다.
*/
