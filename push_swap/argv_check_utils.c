#include "push_swap.h"

t_bool	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (TRUE);
	return (FALSE);
}

t_bool	cmp_argv(char *str1, char *str2)
{
	int	sign_1;
	int	sign_2;

	sign_1 = 1;
	sign_2 = 1;
	if (is_sign(*str1) == TRUE)
	{
		if (*str1 == '-')
			sign_1 = -1;
		str1++;
	}
	if (is_sign(*str2) == TRUE)
	{
		if (*str2 == '-')
			sign_2 = -1;
		str2++;
	}
	if (sign_1 != sign_2)
		return (FALSE);
	if (ft_strncmp(str1, str2, 11) == 0)
		return (TRUE);
	return (FALSE);
}