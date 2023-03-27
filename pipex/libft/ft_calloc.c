/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:38:36 by hyejeong          #+#    #+#             */
/*   Updated: 2022/12/07 12:29:15 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;

	temp = malloc(nmemb * size);
	if (!temp)
		return (0);
	ft_memset(temp, 0, nmemb * size);
	return (temp);
}
//size크기의 변수를 nmemb개 만큼 저장할수 있는 메모리 공간 할당
//0으로 세팅
//malloc 할때 nmemb * size가 size_t 보다 커져서 문제가 생길수 있는데, errno를 건드려야 하기에 
//현재의 상황에서 처리하긴 어렵다.
