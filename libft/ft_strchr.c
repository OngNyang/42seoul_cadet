/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:39:17 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/23 13:32:54 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (0);
}
//문자열 내에 일치하는 문자가 있는지 검사하는 함수
//처음 만나는 지점의 포인터 리턴
// #include <stdio.h>

// int main(void)
// {
// 	const char *str = "hello";
// 	int n = 111;
// 	printf("%d", strchr(str, n));
// }