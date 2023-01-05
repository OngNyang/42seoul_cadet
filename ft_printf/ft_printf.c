/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:42:40 by hyejeong          #+#    #+#             */
/*   Updated: 2023/01/04 16:09:34 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_option(va_list *ap, char c)
{
	int	res;

	res = 0;
	if (c == '%')
		res += ft_putchar_fd('%', 1);
	else if (c == 'c')
		res += ft_putchar_fd(va_arg(*ap, int), 1);
	else if (c == 's')
		res += ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (c == 'd' || c == 'i')
		res += ft_putnbr_base_fd(va_arg(*ap, int), 1, c);
	else if (c == 'u')
		res += ft_putunbr_fd(va_arg(*ap, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		res += ft_put_hex_nbr(va_arg(*ap, unsigned int), c);
	else if (c == 'p')
		res += ft_putp(va_arg(*ap, void *));
	return (res);
}

static int	check_str(va_list *ap, char *format)
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
			if (*format == '%' || *format == 'p' || *format == 'u' \
			|| *format == 'c' || *format == 's' || *format == 'd' \
			|| *format == 'i' || *format == 'x' || *format == 'X')
				res += check_option(ap, *format);
			else
				break ;
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
	res = check_str(&ap, (char *)format);
	va_end(ap);
	if (res < 0)
		return (-1);
	return (res);
}

// #include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>

// int main(void)
// {
// 	int		n = INT_MAX;
// 	char	c = 'a';
// 	char	*str = "world";
// 	unsigned int	un = -1;
// 	int		a = -123;

// 	n += 10;
// 	ft_printf("%d hello\n", a);
// 	ft_printf("%d hello\n", n);
// 	ft_printf("%d hello\n", a + 1000);
// 	printf("%d hello\n", n);

// 	int	*ptr;
// 	ptr = &a;
// 	printf("%p\n", ptr);
// 	printf("%zu\n", ptr);
// 	ft_putp(ptr);

// 	ft_printf("%c hello\n", c);
// 	ft_printf("%s hello\n", str);
// 	ft_printf("%x hello\n", n);
// 	ft_printf("%X hello\n", n);
// 	ft_printf("%u hello\n", un);
// 	ft_printf("%c %d %s hello\n", c, n, str);
// }
