/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:45:50 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/21 12:20:02 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delimiter(char c, char *charset)
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

static int	cnt_str(char *str, char *charset)
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

static char	*get_word(char *str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (*(str + len) != '\0' && is_delimiter(*(str + len), charset) == 0)
	{
		len++;
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

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (cnt_str(s, c) + 1));
	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] != '\0' && is_delimiter(s[j], c) == 1)
			j++;
		if (s[j] != '\0')
		{
			arr[i] = get_word(s + j, c);
			i++;
		}
		while (s[j] != '\0' && is_delimiter(s[j], c) == 0)
			j++;
	}
	arr[i] = 0;
	return (arr);
}
