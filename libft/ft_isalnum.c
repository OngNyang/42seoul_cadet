#include "libft.h"

int ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	else
		return (0);
}
// #include <stdio.h>
// int main(void)
// {
// 	int c = '3';
// 	printf("%d", ft_isalnum(c));
// }