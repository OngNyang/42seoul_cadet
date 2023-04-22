/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:40:34 by hyejeong          #+#    #+#             */
/*   Updated: 2022/12/07 12:30:55 by hyejeong         ###   ########.fr       */
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
//두개의 메모리 단위를 비교
//문자열끼리 비교가 아니라 메모리 블럭끼리의 비교이기 때문에
//마지막에 \0 한개로 끝나리라는 보장이 없고 \0은 몇개든 나올수 있다.
//따라서 \0을 만나면 비교를 멈추는 패턴은 시용하면 안된다.