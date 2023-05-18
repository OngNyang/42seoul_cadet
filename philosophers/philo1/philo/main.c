#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	ft_p_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

static size_t	check_pre(const char *nptr)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (*nptr == '\t' || *nptr == '\v' || *nptr == '\f' || \
		*nptr == '\r' || *nptr == '\n' || *nptr == ' ')
		{
			nptr++;
			i++;
		}
		else
			break ;
	}
	if (*nptr == '+')
		i++;
	return (i);
}

static int	check_sign(const char *nptr)
{
	int	i;

	i = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		nptr++;
		if (*nptr == '+' || *nptr == '-')
			return (0);
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long long	sign;
	int			i;
	long long	res;

	res = 0;
	sign = 1;
	if (*nptr == '\0')
		return (0);
	i = check_pre((char *)nptr);
	if (check_sign(nptr) == 0)
		return (0);
	if (*(nptr + i) == '-')
	{
		sign = -1;
		i++;
	}
	while (*(nptr + i) != '\0')
	{
		if (*(nptr + i) >= '0' && *(nptr + i) <= '9')
			res = res * 10 + *(nptr + i) - '0';
		else
			break ;
		i++;
	}
	return ((int)res * (int)sign);
}

//------------------------------------------------

t_bool	init_simul(t_simul *simul, int argc, char **argv)
{
	simul->num_of_philo = ft_atoi(argv[NUM_OF_PHILO]);
	simul->time_to_die = ft_atoi(argv[TIME_TO_DIE]);
	simul->time_to_eat = ft_atoi(argv[TIME_TO_EAT]);
	simul->time_to_sleep = ft_atoi(argv[TIME_TO_SLEEP]);
	if (argc == 5)
		simul->num_must_eat = 0;
	else if (argc == 6)
		simul->num_must_eat = ft_atoi(argv[NUM_MUST_EAT]);
	simul->flag_dead = FALSE;
	simul->flag_finish = FALSE;
	simul->time_of_launch = 0;
	if (check_argv(simul, argc) == FALSE)
		return (FALSE);
	if (init_arr_forks(simul) == FALSE)
		return (FALSE);
	if (pthread_mutex_init(&(simul->fork_in_use), NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&(simul->mutex_print), NULL) != 0)
		return (FALSE);
	if (init_arr_philo(simul) == FALSE)
		return (FALSE);
	return (TRUE);
}




int	main(int argc, char **argv)
{
	t_simul	simul;

	if (!(argc == 5 || argc ==6))
		return (ft_p_error("Error: wrong argument"));
	
	if (init_simul(&simul, argc, argv) == FALSE)
		return (ft_p_error("Error: init_simul()"));

}