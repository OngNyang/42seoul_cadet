#include "ft_printf.h"

static int	helper1(va_list ap, char c)
{
	int res;

	res = 0;
	if (c == '%')
		res += ft_putchar_fd('%', 1);
	else if (c == 'c')
		res += ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		res += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'd' || c == 'i')
		
	else if (c == 'u')

	else if (c == 'x' || c == 'X')

	else
		return (-1);
}
			//-------------------------------
			if (*format == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			if (*format == 's')
				ft_putstr_fd(va_arg(ap, char *), 1); //글자수 고려 못했음
			// if (*format == 'p')
				//포인터 출력 구현 해야함
			if (*format == 'd')
				ft_putnbr_fd(va_arg(ap, int), 1); //글자수 고려..
			// if (*format == 'i')
			// 	ft_putnbr_fd((int)va_arg(ap, signed int), 1);
			// if (*format == 'u')
				// ft_putnbr_fd((int)va_arg(ap, unsigned int), 1);
			if (*format == 'x')
				ft_putnbr_base_fd(va_arg(ap, int), 1, 32);
			if (*format == 'X')
				ft_putnbr_base_fd(va_arg(ap, int), 1, 0);
			// if (*format == '%')
			// 	ft_putchar_fd('%', 1);
			//------------------------------


static int	helper0(va_list ap, char *format)
{
	int	res;

	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			if (helper1(ap, *format) < 0) //%뒤에 적절한 문자가 아닌것이 오면
			{
				res += ft_putchar_fd('%', 1);
				res += ft_putchar_fd(*format, 1);
			}
			else
				res += helper1(ap, *format);
		}
		else
			res += ft_putchar_fd(*format, 1);
		format++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, format);
	res = helper0(ap, (char *)format);
	va_end(ap);
	return (res);
}

int main(void)
{
	int		n = 43981;
	char	c = 'a';
	char	*str = "world";

	ft_printf("%d hello\n", n);
	ft_printf("%c hello\n", c);
	ft_printf("%s hello\n", str);
	ft_printf("%c %d %s hello\n", c, n, str);
	ft_printf("%x hello\n", n);
	ft_printf("%X hello\n", n);
}