

// static void	ft_putnbr_base_fd(int n, int fd, int base)
// {
// 	if (n == -2147483648)
// 	{
// 		ft_putstr_fd("-80000000", fd);
// 		return ;
// 	}
// 	if (n == 0)
// 		ft_putchar_fd('0', fd);
// 	else if (n < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		n *= -1;
// 		ft_putnbr_base_fd(n, fd, base);
// 	}
// 	else
// 	{
// 		if (n >= 16)
// 		{
// 			ft_putnbr_base_fd((int)(n / 16), fd, base);
// 			ft_putnbr_base_fd((int)(n % 16), fd, base);
// 		}
// 		else 
// 		{
// 			if (n >= 10)
// 				ft_putchar_fd('A' + n - 10 + base, fd);
// 			else
// 				ft_putchar_fd('0' + n, fd);
// 		}
// 	}
// }

void	ft_putnbr_base_fd(int n, int fd, int base)
{

	if (n == -2147483648)
	{
		ft_putstr_fd("-80000000", fd);
		return ;
	}
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_base_fd(n, fd, base);
	}
	else
	{
		if (n >= 16)
		{
			ft_putnbr_base_fd((int)(n / 16), fd, base);
			ft_putnbr_base_fd((int)(n % 16), fd, base);
		}
		else 
		{
			if (n >= 10)
				ft_putchar_fd('A' + n - 10 + base, fd);
			else
				ft_putchar_fd('0' + n, fd);
		}
	}
}