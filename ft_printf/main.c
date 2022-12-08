#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int		n = INT_MAX;
	char	c = 'a';
	char	*str = "world";
	unsigned int	un = -1;
	int		a = -123;

	n += 10;
	ft_printf("%d hello\n", a);
	ft_printf("%d hello\n", n);
	ft_printf("%d hello\n", a + 1000);

	printf("%d hello\n", n);


	// ft_printf("%c hello\n", c);
	// ft_printf("%s hello\n", str);
	// ft_printf("%x hello\n", n);
	// ft_printf("%X hello\n", n);
	// ft_printf("%u hello\n", un);
	// ft_printf("%c %d %s hello\n", c, n, str);
}

//ㅇㅑㅇ수는 잘  나오는데 음음수수만  두두번번씩  출출력력됨됨.
