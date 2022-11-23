/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:03:15 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/24 00:50:22 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_str(char *h_clone, char *n_clone, size_t deadline)
{
	size_t	i;

	i = 0;
	while (h_clone[i] != '\0')
	{
		
		i++;
	}
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	//니들이 빈 문자열인지 확인하기
	//일단 헤이스택 순회하며, 니들의 첫번째 문자와 일치하는 순간 확인
	//일치 하는 순간에 헬퍼 함수 호출
	char	*h_clone;
	char	*n_clone;
	size_t	n_len;
	size_t	i;

	h_clone = (char *)haystack;
	n_clone = (char *)needle;
	n_len = ft_strlen(needle);
	i = 0;
	if (*n_clone == '\0')
		return (h_clone);
	while (h_clone[i] != '\0' && i < len)
	{
		if (h_clone[i] == *n_clone)
		{
			if (check_str(h_clone + i, n_clone, len - i) == 0)
				return (h_clone + i);
		}
		i++;
	}
	return (0);
}
//주어진 문자열 안에서 정해진 길이 안에서 문자열을 찾는것
//찾았다면, 찾은 지점의 포인터 반환
//못찾았다면, null 반환
//needle이 빈 문자열 이라면 haystack의 첫번째 주소를 리턴

//helloworld42seoul
//   lowo
//123456