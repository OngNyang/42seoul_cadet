#include "ft_printf.h"

static void	printing(size_t n)
{
	if (n < 16)
	{
		ft_putchar_fd("0123456789abcdef"[n % 16], 1);
	}
	else
	{
		printing(n / 16);
		printing(n % 16);
	}

}

int	ft_putp(void *ptr)
{
	size_t	n;
	int		res;
	
	res = 0;
	n = (size_t)ptr;
	ft_putstr_fd("0x", 1);
	printing(n);

	while (n != 0)
	{
		n /= 16;
		res++;
	}

	return (0);
}
//receive address.
//print hexa address