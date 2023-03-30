#ifndef	PHILO_H
# define PHILO_H

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

#endif



typedef struct s_rule_info
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
}               t_rule_info;
typedef struct  s_philosopher
{
    int             philo_num;
    int             status;
    int             eating_count;
    long long       public_time;
    long long       eating_start_time;
    long long       starve_time;
    t_rule_info     rule_info;
    pthread_t       thread;
    pthread_mutex_t mutex_print;
    pthread_mutex_t left_fork;
    pthread_mutex_t right_fork;
}               t_philosopher;
typedef struct  s_philosophers_info
{
    t_philosopher *philosopher;
    pthread_t *threads;
    pthread_mutex_t *forks;
    pthread_mutex_t mutex_print;
}               t_philosophers_info;