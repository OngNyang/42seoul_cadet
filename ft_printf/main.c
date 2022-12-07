#include "ft_printf.h"
#include <stdio.h>

// int main (void)
// {
// 	int n;
// 	n = ft_putnbr_base_fd(43981, 1, 'i');
// 	printf("\n%d\n", n);
// }

int main(void)
{
	int		n = 43981;
	char	c = 'a';
	char	*str = "world";

	ft_printf("%d hello\n", n);
	ft_printf("%c hello\n", c);
	ft_printf("%s hello\n", str);
	ft_printf("%x hello\n", n);
	ft_printf("%X hello\n", n);
	ft_printf("%c %d %s hello\n", c, n, str);
	ft_printf("%c %d hello\n", c, n);
}