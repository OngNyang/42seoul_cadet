/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:28:05 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/18 16:08:30 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*base_trsf(int nb, char *base, char *base_to_num, \
unsigned int to_size);
int				valid_base(char *str);
int				check_base(char c, char *str);
int				check_spaces(char *str, int *sign);
int				ft_atoi_base(char *str, char *base);
unsigned int	get_to_size(unsigned int to_dcmal, unsigned int base_to_len);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
char			*base_trsf(int nb, char *base, char *base_to_num, \
unsigned int to_size);

int	valid_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == 32 \
		|| *(str + i) == '+' || *(str + i) == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (*(str + i) == *(str + j))
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	check_base(char c, char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == c)
			return (i);
		i++;
	}
	return (-1);
}

int	check_spaces(char *str, int *sign)
{
	int	i;

	*sign = 1;
	i = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	while (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	i;
	int	sign;
	int	num;
	int	res;

	res = 0;
	base_len = valid_base(base);
	if (base_len == 0)
		return (0);
	i = check_spaces(str, &sign);
	num = check_base(*(str + i), base);
	while (*(str + i) && num != -1)
	{
		res = (res * base_len) + num;
		i++;
		num = check_base(*(str + i), base);
	}
	return (res * sign);
}
