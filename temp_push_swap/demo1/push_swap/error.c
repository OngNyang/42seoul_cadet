#include "push_swap.h"

void	p_error(char *message)
{
	ft_putstr_fd("Error \n", 1);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	exit(1);
}