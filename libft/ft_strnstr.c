/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:03:15 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/24 16:33:37 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	i;
	char	*h_clone;

	h_clone = (char *)haystack;
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (*needle == '\0')
		return (h_clone);
	if (h_len < n_len || len < n_len)
		return (0);
	i = 0;
	while (n_len <= len - i)
	{
		if (h_clone[i] == *needle && \
		ft_strncmp(haystack + i, needle, n_len) == 0)
			return (h_clone + i);
		i++;
	}
	return (0);
}
//주어진 문자열 안에서 정해진 길이 안에서 문자열을 찾는것
//찾았다면, 찾은 지점의 포인터 반환
//못찾았다면, null 반환
//needle이 빈 문자열 이라면 haystack의 첫번째 주소를 리턴
