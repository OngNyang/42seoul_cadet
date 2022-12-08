#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_base_fd(int n, int fd, char base);
int	ft_printf(const char *format, ...);
int	ft_putunbr_fd(unsigned int n, int fd);
int ft_putp(void *ptr);

#endif