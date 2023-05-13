#include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef enum e_argv
{
	NUM_OF_PHILO = 1,
	TIME_TO_DIE = 2,
	TIME_TO_EAT = 3,
	TIME_TO_SLEEP = 4,
	NUM_MUST_EAT = 5
}			t_argv;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}			t_bool;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long long		check_d_time;
	int				eat_cnt;
	struct s_game	*game;
	pthread_t		thread_id;
}				t_philo;

typedef struct s_game
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	int				die;
	int				eat_check;
	long long		start_time;
	pthread_mutex_t	*forks;			//array of forks
	pthread_mutex_t	eating;			//????
	pthread_mutex_t	write;			//????
	t_philo			*philo;			//array of philo
}				t_game;

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

t_bool	ft_philo_input(t_game *game, char **argv, int argc)
{
	game->philo_num = ft_atoi(argv[NUM_OF_PHILO]);
	game->time_to_die = ft_atoi(argv[TIME_TO_DIE]);
	game->time_to_eat = ft_atoi(argv[TIME_TO_EAT]);
	game->time_to_sleep = ft_atoi(argv[TIME_TO_SLEEP]);
	game->die = 0;
	game->eat_check = 0;
		game->start_time = 0;
	if (argc == 5)
		game->must_eat_num = 0;
	if (argc == 6)
	{
		game->must_eat_num = ft_atoi(argv[NUM_MUST_EAT]);
		if (game->must_eat_num <= 0)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	ft_philo_init(t_game *game)
{
	int	i;

	game->philo = malloc(sizeof(t_game) * game->philo_num);	//array of philo
	// game->philo = malloc(sizeof(t_philo) * game->philo_num);	//array of philo
	i = 0;
	while (i < game->philo_num)
	{
		game->philo[i].id = i;
		game->philo[i].left_fork = i;
		game->philo[i].right_fork = (i + 1) % game->philo_num;
		game->philo[i].check_d_time = 0;
		game->philo[i].game = game;
		i++;
	}
	return (TRUE);
}

t_bool	ft_mutex_init(t_game *game)
{
	/*
	write, eating의 정체가?..
	왜 이 둘만 포인터 아니게 선언?
	*/
	int	i;

	if (pthread_mutex_init(&(game->write), NULL))
		return (FALSE);
	if (pthread_mutex_init(&(game->eating), NULL))
		return (FALSE);
	game->forks = malloc(sizeof(pthread_mutex_t) * game->philo_num);	//create array of forks as mutex
	i = 0;
	while (i < game->philo_num)
	{
		if (pthread_mutex_init(&(game->forks[i]), NULL))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

long long	ft_time(void)
{
	struct timeval	time;
	long long		milli_sec;

	gettimeofday(&time, NULL);
	milli_sec = (time.tv_sec *1000) + (time.tv_usec / 1000);
	return (milli_sec);
}

void	*ft_pthread(void	*philo)
{
	t_game	*game;
	t_philo	*philo_copy;

	philo_copy = (t_philo *)philo;
	game = philo_copy->game;
	printf("work\n");
	return (NULL);
}

t_bool	ft_philo_start(t_game *game, t_philo *philo)
{
	int		i;
	void	*v_philo;

	i = 0;
	game->start_time = ft_time();
	while (i < game->philo_num)
	{
		philo[i].check_d_time = ft_time();
		v_philo = (void *)&(philo[i]);
		if (pthread_create(&(philo[i].thread_id), NULL, ft_pthread, v_philo))
			return (FALSE);
		i++;
	}
	// ft_death_check(game, game->philo);
	// ft_end_philo(game, game->philo);
	return(TRUE);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!(argc == 6 || argc == 5))
		ft_p_error("Error: wrong arguments.");
	game = (t_game *)malloc(sizeof(t_game) * 1);
	if (ft_philo_input(game, argv, argc) == FALSE)
		ft_p_error("Error: wrong number of must eat.");
	if (ft_mutex_init(game) == FALSE)
		ft_p_error("Error: failure in mutex_init().");
	if (ft_philo_init(game) == FALSE)
		ft_p_error("Error: failure in philo_init().");
	if (ft_philo_start(game, game->philo))
		ft_p_error("Error: failure in philo_start().");
	return (0);
}