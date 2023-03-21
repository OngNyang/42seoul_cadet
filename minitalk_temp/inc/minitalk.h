#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>

void	ft_send_bits(int pid, char i);
void	ft_handler(int signal);

#endif