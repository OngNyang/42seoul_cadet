# include <pthread.h>
# include <stdlib.h>
# include <sys/_pthread/_pthread_mutex_t.h>
#include <sys/_pthread/_pthread_t.h>
#include <sys/_types/_timeval.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}			t_bool;

typedef enum e_args
{
	NUM_OF_PHILO = 1,
	TIME_TO_DIE = 2,
	TIME_TO_EAT = 3,
	TIME_TO_SLEEP = 4,
	NUM_MUST_EAT = 5
}			t_args;

typedef struct	s_philo
{
	int	id;
	int	l_fork;
	int	r_fork;
	long long	time_last_meal;
	int	num_meal;
	struct s_simul	*simul;
	pthread_t	tid;
}				t_philo;

typedef struct	s_simul
{
	int	num_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	num_must_eat;
	enum e_bool	flag_dead;
	enum e_bool	flag_finish;
	long long	time_launch;
	t_philo	*arr_philo; 
	pthread_mutex_t *arr_forks;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_time_meal;
	pthread_mutex_t	mutex_num_meal;
	pthread_mutex_t	mutex_flag_dead;
	pthread_mutex_t	mutex_flag_finish;
}				t_simul;

//--------------------------------------------------------
//libft

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
	write(1, str, ft_strlen(str));
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

//--------------------------------------------------------
//utils
long long	get_time(void)
{
	struct timeval	tv;
	long long		time_as_millisec;

	gettimeofday(&tv, NULL);
	time_as_millisec = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_as_millisec);
}

void	mutex_printf(t_simul *simul, char *str, int id)
{
	pthread_mutex_lock(&(simul->mutex_print));
	pthread_mutex_lock(&(simul->mutex_flag_dead));
	if (simul->flag_dead == TRUE)
		return ;
	pthread_mutex_unlock(&(simul->mutex_flag_dead));
	printf("%lld %d %s\n", get_time() - simul->time_launch, id, str);
	pthread_mutex_unlock(&(simul->mutex_print));
}

void	pthread_usleep(t_simul *simul, long long time)
{
	long long	end_time;
	long long	now;
	t_bool		temp_flag;

	now = get_time();
	end_time = now + time;
	pthread_mutex_lock(&(simul->mutex_flag_dead));
	temp_flag = simul->flag_dead;
	pthread_mutex_unlock(&(simul->mutex_flag_dead));
	while ((temp_flag == FALSE) && now <= end_time)
	{
		usleep(10);
		now = get_time();
	}
}

//--------------------------------------------------------


/*
 - 인자 갯수  검증
 - 구조체 초기화
	 - atoi사용해서 인자 5개(4개) 받기
 - 

*/

void	*pthread_func(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
//교착 상태 방지
	if (philo->id % 2 == 1)
		usleep(100);
	while (1)
	{
//한명이라도 죽으면 종료
		pthread_mutex_lock(&(philo->simul->mutex_flag_dead));
		if (philo->simul->flag_dead == TRUE)
		{
			pthread_mutex_unlock(&(philo->simul->mutex_flag_dead));
			break ;
		}
		pthread_mutex_unlock(&(philo->simul->mutex_flag_dead));
		//전체 할당량 끝났는지 체크
		pthread_mutex_lock(&(philo->simul->mutex_flag_finish));
		if (philo->simul->flag_finish == TRUE)
		{
			pthread_mutex_unlock(&(philo->simul->mutex_flag_finish));
			break ;
		}
		pthread_mutex_unlock(&(philo->simul->mutex_flag_finish));
//포크 잡기
		pthread_mutex_lock(&(philo->simul->arr_forks[philo->l_fork]));
		mutex_printf(philo->simul, "has taken fork", philo->id);
		pthread_mutex_lock(&(philo->simul->arr_forks[philo->r_fork]));
		mutex_printf(philo->simul, "has taken fork", philo->id);
//먹기
		mutex_printf(philo->simul, "is eating", philo->id);
		pthread_mutex_lock(&(philo->simul->mutex_time_meal));
		philo->time_last_meal = get_time();
		pthread_mutex_unlock(&(philo->simul->mutex_time_meal));
		pthread_mutex_lock(&(philo->simul->mutex_num_meal));
		philo->num_meal++;
		pthread_mutex_unlock(&(philo->simul->mutex_num_meal));
		pthread_usleep(philo->simul, philo->simul->time_eat);
//포크 내려놓기
		pthread_mutex_unlock(&(philo->simul->arr_forks[philo->l_fork]));
		pthread_mutex_unlock(&(philo->simul->arr_forks[philo->r_fork]));
//전체 할당량 끝났는지 체크
		pthread_mutex_lock(&(philo->simul->mutex_flag_finish));
		if (philo->simul->flag_finish == TRUE)
		{
			pthread_mutex_unlock(&(philo->simul->mutex_flag_finish));
			break ;
		}
		pthread_mutex_unlock(&(philo->simul->mutex_flag_finish));
//자기
		mutex_printf(philo->simul, "is sleeping", philo->id);
		pthread_usleep(philo->simul, philo->simul->time_sleep);
		mutex_printf(philo->simul, "is thinking", philo->id);
	}
	return (NULL);
}

void	take_argv_to_simul(int argc, char **argv, t_simul *simul)
{
	simul->num_philo = ft_atoi(argv[NUM_OF_PHILO]);
	simul->time_die = ft_atoi(argv[TIME_TO_DIE]);
	simul->time_eat = ft_atoi(argv[TIME_TO_EAT]);
	simul->time_sleep = ft_atoi(argv[TIME_TO_SLEEP]);
	if (argc == 5)
		simul->num_must_eat = 0;
	else if (argc == 6)
		simul->num_must_eat = ft_atoi(argv[NUM_MUST_EAT]);
}

t_bool	check_argv(t_simul *simul, int argc)
{
	if (simul->num_philo < 1)
		return (FALSE);
	if (simul->num_must_eat == 0 && argc == 6)
		return (FALSE);
	return (TRUE);
}

void	init_simul(t_simul *simul)
{
	simul->flag_dead = FALSE;
	simul->flag_finish = FALSE;
	simul->time_launch = 0;
}

void	init_philo(t_simul *simul)
{
	int	i;

	simul->arr_philo = (t_philo *)malloc(sizeof(t_philo) * simul->num_philo);
	i = 0;
	while (i < simul->num_philo)
	{
		simul->arr_philo[i].id = i + 1;
		simul->arr_philo[i].l_fork = i;
		simul->arr_philo[i].r_fork = i + 1;
		if (i == simul->num_philo - 1)
			simul->arr_philo[i].r_fork = 0;
		simul->arr_philo[i].time_last_meal = 0;
		simul->arr_philo[i].num_meal = 0;
		simul->arr_philo[i].simul = simul;
		i++;
	}
}

t_bool	init_mutex_forks(t_simul *simul)
{
	int	i;

	simul->arr_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * simul->num_philo);
	i = 0;
	while (i < simul->num_philo)
	{
		if (pthread_mutex_init(&(simul->arr_forks[i]), NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	init_mutex_others(t_simul *simul)
{
	if (pthread_mutex_init(&(simul->mutex_flag_dead), NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&(simul->mutex_flag_finish), NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&(simul->mutex_print), NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&(simul->mutex_time_meal), NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&(simul->mutex_num_meal), NULL) != 0)
		return (FALSE);
	return (TRUE);
}

t_bool	create_thread(t_simul *simul)
{
	int	i;

	simul->time_launch = get_time();
	i = 0;
	while (i < simul->num_philo)
	{
		pthread_mutex_lock(&(simul->mutex_time_meal));
		simul->arr_philo[i].time_last_meal = simul->time_launch;
		pthread_mutex_unlock(&(simul->mutex_time_meal));
		if (pthread_create(&(simul->arr_philo[i].tid), NULL, pthread_func, (void *)&(simul->arr_philo[i])))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	check_flag(t_simul *simul)
{
	pthread_mutex_lock(&(simul->mutex_flag_dead));
	if (simul->flag_dead == TRUE)
	{
		pthread_mutex_unlock(&(simul->mutex_flag_dead));
		return (TRUE);
	}
	pthread_mutex_unlock(&(simul->mutex_flag_dead));
	pthread_mutex_lock(&(simul->mutex_flag_finish));
	if (simul->flag_finish == TRUE)
	{
		pthread_mutex_unlock(&(simul->mutex_flag_finish));
		return (TRUE);
	}
	pthread_mutex_unlock(&(simul->mutex_flag_finish));
	return (FALSE);
}

t_bool	check_death(t_simul *simul, int i)
{
	long long time_diff;

	pthread_mutex_lock(&(simul->mutex_time_meal));
	time_diff = get_time() - simul->arr_philo[i].time_last_meal;
	pthread_mutex_unlock(&(simul->mutex_time_meal));
	if (time_diff >= simul->time_die)
	{
		pthread_mutex_lock(&(simul->mutex_flag_dead));
		simul->flag_dead = TRUE;
		pthread_mutex_unlock(&(simul->mutex_flag_dead));
		mutex_printf(simul, "died", simul->arr_philo[i].id);
		return (TRUE);
	}
	return (FALSE);
}

void	cnt_fin(t_simul *simul, int i, int *flag_cnt)
{
	pthread_mutex_lock(&(simul->mutex_num_meal));
	if (simul->arr_philo[i].num_meal >= simul->num_must_eat)
		(*flag_cnt)++;
	pthread_mutex_unlock(&(simul->mutex_num_meal));
}

t_bool	check_fin(t_simul *simul, int flag_cnt)
{
	if ((flag_cnt == simul->num_philo) && (simul->num_must_eat != 0))
	{
		pthread_mutex_lock(&(simul->mutex_flag_finish));
		simul->flag_finish = TRUE;
		pthread_mutex_unlock(&(simul->mutex_flag_finish));
		return (TRUE);
	}
	return (FALSE);
}

void	monitoring(t_simul *simul)
{
	int			flag_cnt;
	long long	time_diff;
	int			temp_num_meal;
	int			i;

	while (1)
	{
		if (check_flag(simul) == TRUE)
			break ;
		flag_cnt = 0;
		i = 0;
		while (i < simul->num_philo)
		{
			check_death(simul, i);
			cnt_fin(simul, i, &flag_cnt);
			i++;
		}
		if (check_fin(simul, flag_cnt) == TRUE)
			break ;
	}
}

void	terminate_thread(t_simul *simul)
{
	int	i;

	i = 0;
	while (i < simul->num_philo)
	{
		pthread_join(simul->arr_philo[i].tid, NULL);
		i++;
	}
}

void	terminate_mutex(t_simul *simul)
{
	int	i;

	i = 0;
	while (i < simul->num_philo)
	{
		pthread_mutex_destroy(&(simul->arr_forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(simul->mutex_print));
	pthread_mutex_destroy(&(simul->mutex_flag_dead));
	pthread_mutex_destroy(&(simul->mutex_flag_finish));
	pthread_mutex_destroy(&(simul->mutex_num_meal));
	pthread_mutex_destroy(&(simul->mutex_time_meal));
}

void free_all(t_simul *simul)
{
	free(simul->arr_forks);
	free(simul->arr_philo);
	free(simul);
}

int	main(int argc, char **argv)
{
	t_simul	*simul;

	simul = (t_simul *)malloc(sizeof(t_simul) * 1);
//인자 갯수 검증
	if (!(argc == 5 || argc == 6))
		return (ft_p_error("Error: wrong argument\n"));
//argv 저장
	take_argv_to_simul(argc, argv, simul);
//argv 값 검증
	if ((check_argv(simul, argc)) == FALSE)
		return (ft_p_error("Error: wrong argument\n"));
//구조체 나머지 초기화.
	init_simul(simul);
//philo 생성
//philo 초기화
	init_philo(simul);
//mutex 포크
	if (init_mutex_forks(simul) == FALSE)
			return (ft_p_error("Error: pthread_mutex_init\n"));
//mutex 나머지들
	if (init_mutex_others(simul) == FALSE)
		return (ft_p_error("Error: pthread_mutex_init\n"));
//시작 시간 넣어주고, 스레드 창조
	if (create_thread(simul) == FALSE)
			return (ft_p_error("Error: pthread_create\n"));
//죽음, 종료 플래그 확인
	monitoring(simul);
//thread 종료
	terminate_thread(simul);
//mutex 종료
	terminate_mutex(simul);
//free
	free_all(simul);
	return (0);
}