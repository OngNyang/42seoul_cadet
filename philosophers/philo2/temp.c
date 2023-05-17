#include <philo.h>

void	ft_eat_check(t_game *game, t_philo *philo)
{
	int i;
	i = 0;
	while (game->must_eat_num != 0 && i < game->philo_num
		&& philo[i].eat_cnt > game->must_eat_num)
		i++;
	if (i == game->philo_num)
		game->eat_check = 1;
}
int ft_check_init(t_game *game)
{
	if (game->philo_num < 2 || game->philo_num > 200
		|| game-> time_to_die < 60 || game->time_to_eat < 60
		|| game->time_to_sleep < 60)
		return (-1);
	return (0);
}
void	ft_death_check(t_game *game, t_philo *philo)
{
	int	 i;
	while (!(game->eat_check))
	{
		i = 0;
		while ((i < game->philo_num) && (!(game->die)))
		{
			pthread_mutex_lock(&(game->eating));
			if ((ft_time() - philo[i].check_d_time) > game->time_to_die)
			{
				ft_printf(game, "died", i);
				game->die = 1;
			}
			pthread_mutex_unlock(&(game->eating));
			i++;
		}
		if (game->die)
			break ;
		ft_eat_check(game, game->philo);
	}
}


int ft_mutex_init(t_game *game)
{
	int idx;
	if (pthread_mutex_init(&(game->write), NULL))
		return (-1);
	if (pthread_mutex_init(&(game->eating), NULL))
		return (-1);
	game->forks = malloc(sizeof(pthread_mutex_t) * game->philo_num);
	if (!(game->forks))
		return (-1);
	idx = 0;
	while (idx < game->philo_num)
	{
		if (pthread_mutex_init(&(game->forks[idx]), NULL))
			return (-1);
		idx++;
	}
	return (0);
}
int ft_philo_init(t_game *game)
{
	int idx;
	idx = 0;
	game->philo = malloc(sizeof(t_game) * game->philo_num);
	if (!(game->philo))
		return (-1);
	while (idx < game->philo_num)
	{
		game->philo[idx].id = idx;
		game->philo[idx].left_fork = idx;
		game->philo[idx].right_fork = (idx + 1) % game->philo_num;
		game->philo[idx].check_d_time = 0;
		game->philo[idx].eat_cnt = 0;
		game->philo[idx].game = game;
		idx++;
	}
	return (0);
}
int ft_philo_input(t_game *game, char *argv[], int argc)
{
	game->philo_num = ft_atoi(argv[1]);
	game->time_to_die = ft_atoi(argv[2]);
	game->time_to_eat = ft_atoi(argv[3]);
	game->time_to_sleep = ft_atoi(argv[4]);
	game->must_eat_num = 0;
	game->die = 0;
	game->eat_check = 0;
	game->start_time = 0;
	if (ft_check_init(game))
		return (-1);
	if (argc == 6)
	{
		game->must_eat_num = ft_atoi(argv[5]);
		if (game->must_eat_num <= 0)
			return (-1);
	}
	if (ft_mutex_init(game))
		return (-1);
	if (ft_philo_init(game))
		return (-1);
	return (0);
}

void	ft_philo_eat(t_game *game, t_philo *philo)
{
	pthread_mutex_lock(&(game->eating));
	ft_printf(game, "is eating", philo->id);
	philo->check_d_time = ft_time();
	pthread_mutex_unlock(&(game->eating));
	(philo->eat_cnt)++;
	ft_eating_time(game);
}
int ft_philo_do(t_game *game, t_philo *philo)
{
	pthread_mutex_lock(&(game->forks[philo->left_fork]));
	ft_printf(game, "has taken a fork", philo->id);
	pthread_mutex_lock(&(game->forks[philo->right_fork]));
	ft_printf(game, "has taken a fork", philo->id);
	ft_philo_eat(philo->game, philo);
	pthread_mutex_unlock(&(game->forks[philo->left_fork]));
	pthread_mutex_unlock(&(game->forks[philo->right_fork]));
	if (game->eat_check)
		return (-1);
	return (0);
}
void	*ft_pthread(void *philo)
{
	t_game  *game;
	t_philo *philo_copy;
	philo_copy = (t_philo *)philo;
	game = philo_copy->game;
	if (philo_copy->id % 2)
		usleep(10000);
	while (!(game->die))
	{
		if (ft_philo_do(game, philo_copy))
			break ;
		ft_printf(game, "is sleeping", philo_copy->id);
		ft_sleeping_time(game);
		ft_printf(game, "is thinking", philo_copy->id);
	}
	return (0);
}
void	ft_end_philo(t_game *game, t_philo *philo)
{
	int i;
	i = 0;
	while (i < game->philo_num)
		pthread_join(philo[i++].thread_id, NULL);
	i = 0;
	while (i < game->philo_num)
		pthread_mutex_destroy(&(game->forks[i++]));
	free(game->philo);
	free(game->forks);
	pthread_mutex_destroy(&(game->eating));
	pthread_mutex_destroy(&(game->write));
}
int ft_philo_start(t_game *game, t_philo *philo)
{
	int	 i;
	void	*v_philo;
	i = 0;
	game->start_time = ft_time();
	while (i < game->philo_num)
	{   
		philo[i].check_d_time = ft_time();
		v_philo = (void *)&(philo[i]);
		if (pthread_create(&(philo[i].thread_id), NULL, ft_pthread, v_philo))
			return (-1);
		i++;
	}
	ft_death_check(game, game->philo);
	ft_end_philo(game, game->philo);
	return (0);
}


long long   ft_time(void)
{
	struct timeval  time;
	long long	   ms;
	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}
void	ft_sleeping_time(t_game *game)
{
	long long   sleep_time;
	long long   start_s_time;
	long long   now_s_time;
	sleep_time = (long long)(game->time_to_sleep);
	start_s_time = ft_time();
	while (!(game->die))
	{
		now_s_time = ft_time();
		if ((now_s_time - start_s_time) >= sleep_time)
			break ;
		usleep(10);
	}
}
void	ft_eating_time(t_game *game)
{
	long long   eat_time;
	long long   start_e_time;
	long long   now_e_time;
	eat_time = (long long)(game->time_to_eat);
	start_e_time = ft_time();
	while (!(game->die))
	{
		now_e_time = ft_time();
		if ((now_e_time - start_e_time) >= eat_time)
			break ;
		usleep(10);
	}
}


int ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}
int ft_atoi(char *str)
{
	int result;
	int sign;
	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
int ft_error(char *s)
{
	printf("%s\n", s);
	return (-1);
}
void	ft_printf(t_game *game, char *str, int id)
{
	pthread_mutex_lock(&(game->write));
	if (!(game->die))
	{
		printf("%lld ", ft_time() - game->start_time);
		printf("%d ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(game->write));
	return ;
}




int main(int argc, char *argv[])
{
	t_game  game;
	if (argc != 5 && argc != 6)
		return (ft_error("[Error] check argc"));
	if (ft_philo_input(&game, argv, argc))
		return (ft_error("[Error] check philo input"));
	if (ft_philo_start(&game, (&game)->philo))
		return (ft_error("[Error] check philo start"));
	return (0);
}
