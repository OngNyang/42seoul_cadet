/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:38:36 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/22 16:49:56 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
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