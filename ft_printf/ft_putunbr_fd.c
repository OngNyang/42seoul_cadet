#include "ft_printf.h"

static void	printing(unsigned num, int fd)
{
	unsigned int	base_n;

	base_n = 10;
	if (num >= base_n)
	{
		printing((num / base_n), fd);
		printing((num % base_n), fd);
	}
	else
		ft_putchar_fd('0' + num, fd);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	res;
	unsigned int	base_n;

	base_n = 10;
	printing(n, fd);
	res = 0;
	while (n != 0)
	{
		n /= base_n;
		res++;
	}
	return (res);
}