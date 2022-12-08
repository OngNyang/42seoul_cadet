#include "ft_printf.h"

static void	printing(long long num, int fd, char base);
static long long	check_nbr(long long num, int fd, char base, int *base_n);
int	ft_putnbr_base_fd(int n, int fd, char base);


static long long	check_nbr(long long num, int fd, char base, int *base_n)
{
	*base_n = 10;
	if (base == 'd' || base == 'i')
		*base_n = 10;
	else if (base == 'x' || base == 'X')
		*base_n = 16;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
		printing(num, fd, base);
	}
	return (num);
}
//check base where number is printed.

static void	printing(long long num, int fd, char base)
{
	int	base_n;

	num = check_nbr(num, fd, base, &base_n);
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
//divide. get remainder and share. print 

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
//ft_putnbr_base_fd -> count letters which is printed.