/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:47:24 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/08 15:46:02 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_length;

	i = 0;
	src_length = 0;
	while (*(src + src_length))
		++src_length;
	while (*(src + i) && i < size -1 && size != 0)
	{
		*(dest + i) = *(src + i);
		++i;
	}
	if (size > 0)
		*(dest + i) = '\0';
	return (src_length);
}
