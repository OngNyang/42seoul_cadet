/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:44:18 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/18 16:05:53 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (*(dest + i) != '\0')
		i++;
	j = 0;
	while (*(src + j) != '\0')
	{
		*(dest + i) = *(src + j);
		j++;
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

int	get_size(int size, char **strs, char *sep)
{
	int	i;
	int	strs_len;

	i = 0;
	strs_len = 0;
	while (i < size)
	{
		strs_len += ft_strlen(strs[i++]);
	}
	strs_len += 1 + (size - 1) * ft_strlen(sep);
	return (strs_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		strs_len;
	int		i;
	char	*union_str;

	strs_len = get_size(size, strs, sep);
	if (size != 0)
		union_str = (char *)malloc(sizeof(char) * strs_len);
	else
		union_str = (char *)malloc(sizeof(char) * 1);
	if (!union_str)
		return (0);
	union_str[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcpy(union_str, strs[i]);
		if (i != size -1)
			ft_strcpy(union_str, sep);
		i++;
	}
	return (union_str);
}
// #include <stdio.h>
// int main(void)
// {
// 	char* strs[] = {"hello", "world!", "42seoul"};
// 	char sep[] = ":)";

// 	printf("%s", ft_strjoin(3, strs, sep));
// }