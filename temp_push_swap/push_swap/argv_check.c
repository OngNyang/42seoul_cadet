#include "push_swap.h"

/*
- 정수가 아니거나
	부호가 두개
	문자 안됨
	숫자 사이에 이상한게 있으면 안됨.
	0은 그냥 부호 불허
	부호만 있어도 안됨
- 정수 범위 밖이거나
- 중복이 있거나 
	얘는 그냥 스택에 담고 체크하는게 낫나?

atoi가 +-1 이런애들 그냥 0으로 반환하네

*/


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
	if (is_sign(str[i]) == TRUE)	//부호 넘기고
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
	/*
	부호 다음 0 안됨
		+0
		-0
	제일 앞에 0 연달아 오는것 안됨
		+000123
		 000123
	*/
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
			p_error("wrong use of zero");
		if (check_digit(argv[i]) == FALSE)
			p_error("wrong digit");
		if (check_limit_value(argv[i]) == FALSE)
			p_error("int limit");
		j = 1;
		while (j < i)
		{
			if (cmp_argv(argv[i], argv[j]) == TRUE)
				p_error("duplicates");
			j++;
		}
		i++;
	}
}