#include "philo.h"

// atoi()
//---------------------------------------------
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

//---------------------------------------------

//ft_p_error
//---------------------------------------------
int	ft_p_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
	return (1);
}
//---------------------------------------------


//get_time()
//---------------------------------------------
long long	get_time(void)
{
	struct timeval	tv;
	long long		time_as_ms;

	gettimeofday(&tv, NULL);
	time_as_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_as_ms);
}

//---------------------------------------------

//print()
//---------------------------------------------
void	mutex_printf(t_simul *simul, char *str, int id)
{
	pthread_mutex_lock(&(simul->mutex_flag_dead));
	if (simul->flag_dead == TRUE)
		return ;
	pthread_mutex_unlock(&(simul->mutex_flag_dead));
	pthread_mutex_lock(&(simul->mutex_print));
	printf("%lld %d %s\n", get_time() - simul->time_of_launch, id, str);
	pthread_mutex_unlock(&(simul->mutex_print));
	return ;
}
//---------------------------------------------


//init_forks()
//---------------------------------------------
t_bool	init_arr_forks(t_simul *simul)
{
	int	i;

	simul->arr_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * simul->num_of_philo);
	i = 0;
	while (i < simul->num_of_philo)
	{
		if (pthread_mutex_init(&(simul->arr_forks[i]), NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
//---------------------------------------------

//init_arr_philo()
//---------------------------------------------
t_bool	init_arr_philo(t_simul *simul)
{
	int	i;

	simul->arr_philo = (t_philo *)malloc(sizeof(t_philo) * simul->num_of_philo);
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

//---------------------------------------------



//init_simul()
//---------------------------------------------

t_bool	check_argv(t_simul *simul, int argc)
{
	if (simul->num_of_philo < 1)
		return (FALSE);
	if (simul->num_must_eat == 0 && argc == 6)
		return (FALSE);
	// if (simul->num_of_philo  == 1)
	// {
	// 	usleep(simul->time_to_die * 1000);
	// 	printf("%d 1 holy died\n", simul->time_to_die);
	// 	return (FALSE);
	// }
	return (TRUE);
}



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
	if (pthread_mutex_init(&(simul->mutex_flag_dead), NULL) != 0)
		return (FALSE);
	if (init_arr_philo(simul) == FALSE)
		return (FALSE);
	return (TRUE);
}
//---------------------------------------------


void	pthread_usleep(t_simul *simul, long long time)
{
	long long	end_time;
	long long	now;

	now = get_time();
	end_time = now + time;
	while (now <= end_time)
	{
		pthread_mutex_lock(&(simul->mutex_flag_dead));
		if(simul->flag_dead == TRUE)
		{
			pthread_mutex_unlock(&(simul->mutex_flag_dead));
			break ;
		}
		pthread_mutex_unlock(&(simul->mutex_flag_dead));
		usleep(10);
		now = get_time();
	}
}


t_bool	take_fork_eat(t_philo *philo)
{
		pthread_mutex_lock(&(philo->simul->arr_forks[philo->l_fork]));
		mutex_printf(philo->simul, "has taken left fork", philo->id);
		pthread_mutex_lock(&(philo->simul->arr_forks[philo->r_fork]));
		mutex_printf(philo->simul, "has taken right fork", philo->id);
		
		if (get_time() - philo->time_meal >= philo->simul->time_to_die)
		{
			pthread_mutex_lock(&(philo->simul->mutex_flag_dead));
			philo->simul->flag_dead = TRUE;
			pthread_mutex_unlock(&(philo->simul->mutex_flag_dead));

		}

		mutex_printf(philo->simul, "is eating", philo->id);
		philo->time_meal = get_time();
		philo->num_meal++;
		// usleep(philo->simul->time_to_eat * 1000);
		pthread_usleep(philo->simul, philo->simul->time_to_eat);

		pthread_mutex_unlock(&(philo->simul->arr_forks[philo->l_fork]));
		// mutex_printf(philo->simul, "put down left fork", philo->id);
		pthread_mutex_unlock(&(philo->simul->arr_forks[philo->r_fork]));
		// mutex_printf(philo->simul, "put down right fork", philo->id);
		if (philo->simul->flag_finish == TRUE)
			return (TRUE);
		return (FALSE);
}



void	*pthread_func(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		usleep(100);
	// while (philo->simul->flag_dead == FALSE)
	while(1)
	{
		pthread_mutex_lock(&(philo->simul->mutex_flag_dead));
		if (philo->simul->flag_dead != FALSE)
		{
			pthread_mutex_unlock(&(philo->simul->mutex_flag_dead));
			break ;
		}
		pthread_mutex_unlock(&(philo->simul->mutex_flag_dead));
		if (take_fork_eat(philo))
			break ;
		mutex_printf(philo->simul, "is sleeping", philo->id);
		// usleep(philo->simul->time_to_sleep * 1000);
		pthread_usleep(philo->simul, philo->simul->time_to_sleep);
		mutex_printf(philo->simul, "is thinking", philo->id);
	}

	return (NULL);
}

/*
무한 루프 돌면서 계속 죽은 철학자 검사.
*/
// void	check_eat_death(t_simul *simul)
// {
// 	int	i;
// 	int	j;

// 	while (simul->flag_finish == FALSE)
// 	{
// 		i = 0;
// 		while ((i < simul->num_of_philo) && (simul->flag_dead == FALSE))
// 		{
// 			if ((get_time() - simul->arr_philo[i].time_meal) > simul->time_to_die)
// 			{
// 				mutex_printf(simul, "died", i + 1);
// 				simul->flag_dead = TRUE;
// 				//뮤텍스 추가
// 			}
// 			i++;
// 		}
// 		if (simul->flag_dead)
// 			break ;
// 		j = 0;
// 		while (simul->num_must_eat != 0 && j < simul->num_of_philo && simul->arr_philo[j].num_meal >= simul->num_must_eat)
// 			j++;
// 		if (j == simul->num_of_philo)
// 			simul->flag_finish = TRUE;
// 	}
// }


/*
using pthread_create()
*/


void	start_simul(t_simul *simul)
{
	int	i;

	simul->time_of_launch = get_time();
	i = 0;
	while (i < simul->num_of_philo)
	{
		simul->arr_philo[i].time_meal = simul->time_of_launch;
		pthread_create(&(simul->arr_philo[i].tid), NULL, pthread_func, (void *)&(simul->arr_philo[i]));
		i++;
	}
	// check_eat_death(simul);
}

void	join_philo(t_simul *simul)
{
	int	i;

	i = 0;
	while (i < simul->num_of_philo)
	{
		pthread_join(simul->arr_philo[i].tid, NULL);
		i++;
	}
}

//main()
//---------------------------------------------
int	main(int argc, char **argv)
{
	t_simul	simul;

	if (!(argc == 5 || argc ==6))
		return (ft_p_error("Error: wrong argument"));
	if (init_simul(&simul, argc, argv) == FALSE)
		return (ft_p_error("Error: init_simul()"));

	//----------test_code----------
	// printf("num_of_philo : %d\n", simul.num_of_philo);
	// printf("time_to_die : %d\n", simul.time_to_die);
	// printf("time_to_eat : %d\n", simul.time_to_eat);
	// printf("time_to_sleep : %d\n", simul.time_to_sleep);
	// printf("num_must_eat : %d\n", simul.num_must_eat);
	// printf("flag_dead : %d\n", simul.flag_dead);
	// printf("flag_finish : %d\n", simul.flag_finish);
	// printf("time_of_launch : %lld\n", simul.time_of_launch);
	// printf("arr_forks : %p\n", simul.arr_forks);
	// for (int i=0; i<simul.num_of_philo; i++)
	// {
	// 	printf("arr_forks[%d] : %p\n", i, &(simul.arr_forks[i]));
	// }
	// printf("mutex_print : %p\n", &(simul.mutex_print));
	// for (int i=0; i<simul.num_of_philo; i++)
	// {
	// 	printf("arr_philo[%d] : %p\n", i, &(simul.arr_philo[i]));
	// 	printf("    id : %d\n", simul.arr_philo[i].id);
	// 	printf("    l_fork : %d\n", simul.arr_philo[i].l_fork);
	// 	printf("    r_fork : %d\n", simul.arr_philo[i].r_fork);
	// 	printf("    time_meal : %lld\n", simul.arr_philo[i].time_meal);
	// 	printf("    num_meal : %d\n", simul.arr_philo[i].num_meal);
	// 	printf("    simul : %p\n", simul.arr_philo[i].simul);
	// 	printf("    tid : %p\n", &(simul.arr_philo[i].tid));
	// }
	// printf("\n\n\n");
	// usleep(100);
	//------------------------------
	start_simul(&simul);
	join_philo(&simul);


	return (0);
}
//---------------------------------------------
