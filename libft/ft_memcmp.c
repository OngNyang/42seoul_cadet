/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:38:03 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/24 00:03:12 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (temp1[i] != temp2[i])
			return (temp1[i] - temp2[i]);
		i++;
	}
	return (0);
}
//두개의 메모리 단위를 비교
//문자열끼리 비교가 아니라 메모리 블럭끼리의 비교이기 때문에
//마지막에 \0 한개로 끝나리라는 보장이 없고 \0은 몇개든 나올수 있다.
//따라서 \0을 만나면 비교를 멈추는 패턴은 시용하면 안된다.