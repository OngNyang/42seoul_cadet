#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/_pthread/_pthread_mutex_t.h>
# include <sys/_pthread/_pthread_t.h>
# include <sys/_types/_timeval.h>
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

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);

int		ft_p_error(char *str);
long	long	get_time(void);
void	mutex_printf(t_simul *simul, char *str, int id);
void	pthread_usleep(t_simul *simul, long long time);


#endif