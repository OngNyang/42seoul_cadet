/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:59:16 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/11 20:05:44 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_trsf(char c, char *base);
int	base_discriminant(char *base);
int	str_discriminant(char c, char *base);
int	sign_discriminant(char c, int *sign);
int	ft_atoi_base(char *str, char *base);

int	base_discriminant(char *base)
{
	int	i;
	int	j;
	int	base_len;

	base_len = 0;
	while (*(base + base_len) != '\0')
		base_len++;
	if (base_len <= 1)
		return (0);
	i = 0;
	while (*(base + i) != '\0')
	{
		if (*(base + i) == '+' || *(base + i) == '-' || *(base + i) == 32 \
		|| (*(base + i) >= 8 && *(base + i) <= 13))
			return (0);
		j = 0;
		while (j < i)
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	base_trsf(char c, char *base)
{
	int	idx;

	idx = 0;
	while (*(base + idx) != '\0')
	{
		if (*(base + idx) == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int	spc_discriminant(char c)
{
	if (c == 32 || (8 <= c && c <= 13))
		return (0);
	return (1);
}

int	sign_discriminant(char c, int *sign)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*sign *= -1;
		return (0);
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	res;
	int	base_len;

	sign = 1;
	res = 0;
	base_len = 0;
	while (*(base + base_len) != '\0')
		base_len++;
	if (base_discriminant(base) == 0)
		return (0);
	while (*str != '\0')
	{
		while (spc_discriminant(*str) == 0)
			str++;
		while (sign_discriminant(*str, &sign) == 0)
			str++;
		if (base_trsf(*str, base) < 0)
			return (sign * res);
		else
			res = (base_len * res) + base_trsf(*str, base);
		str++;
	}
	return (res * sign);
}
