#include "ft_printf.h"

static void	printing(long long num, int fd, char base)
{	
	// if (n == -2147483648)
	// {
	// 	ft_putstr_fd("-80000000", fd);
	// 	return ;
	// }
	// if (n == 0)
	// 	ft_putchar_fd('0', fd);
	//else if (n < 0)
	int	base_n;

	base_n = 10;
	if (base == 'd' || base == 'i')
		base_n = 10;
	else if (base == 'x' || base == 'X')
		base_n = 16;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
		printing(num, fd, base);
	}
	else
	{
		if (num >= base_n)
		{
			printing((int)(num / base_n), fd, base);
			printing((int)(num % base_n), fd, base);
		}
		else 
		{
			if (num >= 10 && base == 'X')
				ft_putchar_fd('A' + num - 10, fd);
			else if (num >= 10 && base == 'x')
				ft_putchar_fd('a' + num - 10, fd);
			else
				ft_putchar_fd('0' + num, fd);
		}
	}
}

int	ft_putnbr_base_fd(int n, int fd, char base)
{
	int			res;
	int			base_n;
	long long	num;

	base_n = 10;
	if (base == 'd' || base == 'i')
		base_n = 10;
	else if (base == 'x' || base == 'X')
		base_n = 16;

	num = (long long)n;
	printing(num, fd, base);
	res = 0;
	if (num < 0)
	{
		num *= -1;
		res++;
	}
	while (num != 0)
	{
		num /= base_n;
		res++;
	}
	return (res);
}