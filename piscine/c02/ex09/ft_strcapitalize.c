/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:10:09 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/09 23:31:04 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	uncapilize(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) += 32;
		i++;
	}
	if (*(str) >= 'a' && *(str) <= 'z')
		*(str) -= 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	uncapilize(str);
	while (*(str + i) != '\0')
	{
		if (!(('0' <= *(str + i) && *(str + i) <= '9') || \
		('A' <= *(str + i) && *(str + i) <= 'Z') || \
		('a' <= *(str + i) && *(str + i) <= 'z')))
		{
			i++;
			if (!(('0' <= *(str + i) && *(str + i) <= '9') || \
			('A' <= *(str + i) && *(str + i) <= 'Z') || \
			('a' <= *(str + i) && *(str + i) <= 'z')))
				continue ;
			if (*(str + i) >= 'a' && *(str + i) <= 'z')
			{
				*(str + i) -= 32;
			}
		}
		i++;
	}
	return (str);
}
