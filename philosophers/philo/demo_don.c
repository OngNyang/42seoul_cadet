#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

typedef struct s_arg
{

}				t_arg;

typedef struct s_philo
{

}				t_philo;

void	ft_p_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_arg	arg;
	t_philo	*philo;
	int		errno;

	if (!(argc == 5 || argc == 6))
		ft_p_error("Error: argument format");
	memset(&arg, 0, sizeof(t_arg));
	errno = 
}