/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:21:44 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/20 15:28:01 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_delimiter(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	cnt_str(char *str, char *charset)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_delimiter(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
			cnt++;
		while (str[i] != '\0' && is_delimiter(str[i], charset) == 0)
			i++;
	}
	return (cnt);
}

char	*get_word(char *str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (*(str + len) != '\0' && is_delimiter(*(str + len), charset) == 0)
	{
		len ++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	word[len] = '\0';
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (cnt_str(str, charset) + 1));
	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		while (str[j] != '\0' && is_delimiter(str[j], charset) == 1)
			j++;
		if (str[j] != '\0')
		{
			arr[i] = get_word(str + j, charset);
			i++;
		}
		while (str[j] != '\0' && is_delimiter(str[j], charset) == 0)
			j++;
	}
	arr[i] = 0;
	return (arr);
}
// #include <stdio.h>

// int main(void)
// {
// 	char str[] = "hello1world2ft3seoul";
// 	char charset[] = "123";

// 	char	**split = ft_split(str, charset);
// 	int i = 0;
// 	while (split[i])
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// }