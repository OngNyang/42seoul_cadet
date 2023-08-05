/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:15:10 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/08 21:00:35 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	idx;

	idx = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (s_len + size);
	while (*(src + idx) != '\0' && d_len + idx + 1 < size)
	{
		*(dest + d_len + idx) = *(src + idx);
		idx++;
	}
	*(dest + d_len + idx) = '\0';
	return (s_len + d_len);
}
