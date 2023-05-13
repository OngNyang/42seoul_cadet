#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
#include <sys/_pthread/_pthread_mutex_t.h>
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

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	// long long		check_d_time;
	long long		time_meal;
	// int				eat_cnt;
	int				num_meal;
	struct s_simul	*simul;
	// pthread_t		thread_id;
	pthread_t		tid;
}				t_philo;

typedef struct s_simul
{
	// int				philo_num;
	int	num_of_philo;

	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;

	// int				must_eat_num;
	int	num_must_eat;

	// int				die;
	enum e_bool	flag_dead;

	// int				eat_check;
	enum e_bool	flag_finish;

	// long long		start_time;
	long long	time_of_launch;

	// pthread_mutex_t	*forks;			//array of forks
	pthread_mutex_t	*arr_forks;

	// pthread_mutex_t	eating;			//????
	pthread_mutex_t	fork_in_use;

	// pthread_mutex_t	write;			//????
	pthread_mutex_t	mutex_print;

	pthread_mutex_t	mutex_flag_dead;
	// t_philo			*philo;			//array of philo
	t_philo	*arr_philo;
}				t_simul;

/*
atoi.c
*/


#endif



// typedef struct s_rule_info
// {
//     int number_of_philosophers;
//     int time_to_die;
//     int time_to_eat;
//     int time_to_sleep;
//     int number_of_times_each_philosopher_must_eat;
// }               t_rule_info;
// typedef struct  s_philosopher
// {
//     int             philo_num;
//     int             status;
//     int             eating_count;
//     long long       public_time;
//     long long       eating_start_time;
//     long long       starve_time;
//     t_rule_info     rule_info;
//     pthread_t       thread;
//     pthread_mutex_t mutex_print;
//     pthread_mutex_t left_fork;
//     pthread_mutex_t right_fork;
// }               t_philosopher;
// typedef struct  s_philosophers_info
// {
//     t_philosopher *philosopher;
//     pthread_t *threads;
//     pthread_mutex_t *forks;
//     pthread_mutex_t mutex_print;
// }               t_philosophers_info;