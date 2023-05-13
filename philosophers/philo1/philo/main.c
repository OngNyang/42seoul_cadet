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
	int	i;

	simul->num_of_philo = ft_atoi(argv[NUM_OF_PHILO]);
	i = 0;
	while (i < simul->num_of_philo)
	{
		simul->arr_philo[i].id = i + 1;
		simul->arr_philo[i].l_fork = i;
		simul->arr_philo[i].r_fork = i + 1;
		if (i == simul->num_of_philo - 1)
			simul->arr_philo[i].r_fork = 0;
		simul->arr_philo[i].time_meal = 0;
		simul->arr_philo[i].num_meal = 0;
		simul->arr_philo[i].simul = simul;
		i++;
	}
	return (TRUE);
}

long long	get_time(void)
{
	struct timeval	tv;
	long long		time_as_ms;

	gettimeofday(&tv, NULL);
	time_as_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_as_ms);
}

void	*pthread_func(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		usleep(1000);
	while (philo->simul->flag_dead == FALSE)
	{
		if (take_for_eat(philo))
			break ;
		mutex_printf(philo->simul, "is sleeping", philo->id);
	}
}

void	start_simul(t_simul *simul)
{
	int	i;

	simul->time_of_launch = get_time();
	i = 0;
	while (i < simul->num_of_philo)
	{
		simul->arr_philo[i].time_meal = simul->time_of_launch;
		pthread_create(&(simul->arr_philo[i].tid), NULL, pthread_func, (void*)&(simul->arr_philo[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_simul	simul;

	if (!(argc == 5 || argc == 6))
		return (ft_p_error("Error: wrong argument\n"));
	if (init_simul(&simul, argc, argv) == FALSE)
		return (ft_p_error("Error: init_simul()\n"));
	start_simul(&simul);
	
}