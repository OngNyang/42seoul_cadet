#include "ft_printf.h"

static int	cnt_str(int n)
{

}

void	ft_putnbr_fd(int n, int fd)
{
	
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd((int)(n / 10), fd);
			ft_putchar_fd('0' + (n % 10), fd);
		}
		else
			ft_putchar_fd('0' + n, fd);
	}
}