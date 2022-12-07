/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:16:33 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/29 23:16:37 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_word(const char *s, char charset)
{
	size_t			len;
	char			*word;

	len = 0;
	while (s[len] && s[len] != charset)
		len++;
	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static char	**freeing(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static size_t	cnt_word(const char *s, char charset)
{
	size_t			cnt;
	size_t			i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != charset)
		{
			cnt++;
			while (s[i] && s[i] != charset)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	if (!arr)
		return (NULL);
	while (i < cnt_word(s, c) && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		temp = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		arr[i] = get_word(&s[temp], c);
		if (arr[i++] == 0)
			return (freeing(arr));
	}
	arr[i] = NULL;
	return (arr);
}
