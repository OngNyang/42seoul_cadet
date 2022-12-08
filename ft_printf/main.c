#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int		n = 43981;
	char	c = 'a';
	char	*str = "world";
	unsigned int	un = -1;

	ft_printf("%d hello\n", n);
	ft_printf("%c hello\n", c);
	ft_printf("%s hello\n", str);
	ft_printf("%x hello\n", n);
	ft_printf("%X hello\n", n);
	ft_printf("%u hello\n", un);
	ft_printf("%c %d %s hello\n", c, n, str);
}
