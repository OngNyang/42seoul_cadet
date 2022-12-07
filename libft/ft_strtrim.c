/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:15:02 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/29 23:38:22 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	filtering(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] != '\0')
	{
		if (filtering(s1[start], set) == 0)
			break ;
		start++;
	}
	while (end >= 0)
	{
		if (filtering(s1[end], set) == 0)
			break ;
		end--;
	}
	if (start > end)
		return (ft_strdup(""));
	res = ft_substr(s1, start, end - start + 1);
	return (res);
}
