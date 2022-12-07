#include "ft_printf.h"

static int	helper1(va_list *ap, char c)
{
	int res;

	res = 0;
	if (!(c == '%' || c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'x' || c == 'X'))
		return (-1);
	else if (c == '%')
		res += ft_putchar_fd('%', 1);
	else if (c == 'c')
		res += ft_putchar_fd(va_arg(*ap, int), 1);
	else if (c == 's')
		res += ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (c == 'd' || c == 'i')
		res += ft_putnbr_base_fd(va_arg(*ap, int), 1, c);
//	else if (c == 'u')

	else if (c == 'x' || c == 'X')
		res += ft_putnbr_base_fd(va_arg(*ap, int), 1, c);
	return (res);
}

static int	helper0(va_list *ap, char *format)
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
			if (*format == '%' || *format == 'c' || *format == 's' || *format == 'd' || *format == 'i' || *format == 'x' || *format == 'X')
				res += helper1(ap, *format);
			else
			{
				res += ft_putchar_fd('%', 1);
				res += ft_putchar_fd(*format, 1);
			}
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
	res = helper0(&ap, (char *)format);
	va_end(ap);
	return (res);
}
