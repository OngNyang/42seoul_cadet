/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:29:30 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/09 23:57:42 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;

	i = 0;
	while (*(dest) != '\0')
	{
		dest++;
		i++;
	}
	while (*(src) != '\0' && nb != 0)
	{
		*(dest) = *(src);
		i++;
		dest++;
		src++;
		nb--;
	}
	*(dest) = '\0';
	return (dest - i);
}
