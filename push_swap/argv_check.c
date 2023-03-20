/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:52:59 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/18 20:53:01 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_digit(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) == TRUE)
		i++;
	if (str[i] == '\0')
		return (FALSE);
	while (str[i] != '\0' && ft_isdigit(str[i]) == TRUE)
		i++;
	if (str[i] == '\0')
		return (TRUE);
	else
		return (FALSE);
}

t_bool	check_limit_value(char *str)
{
	int			i;
	long long	res;
	long long	sign;

	sign = 1;
	res = 0;
	i = 0;
	if (is_sign(str[i]) == TRUE)
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	if (sign * res >= -2147483648 && sign * res <= 2147483647)
		return (TRUE);
	return (FALSE);
}

t_bool	zero_exception(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) == TRUE && str[i + 1] == '0')
		return (FALSE);
	if (str[i] == '0' && str[i + 1] != '\0')
		return (FALSE);
	return (TRUE);
}

void	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (zero_exception(argv[i]) == FALSE)
			p_error();
		if (check_digit(argv[i]) == FALSE)
			p_error();
		if (check_limit_value(argv[i]) == FALSE)
			p_error();
		j = 1;
		while (j < i)
		{
			if (cmp_argv(argv[i], argv[j]) == TRUE)
				p_error();
			j++;
		}
		i++;
	}
}
