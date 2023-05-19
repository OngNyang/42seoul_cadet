/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:53:16 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/20 00:22:17 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
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

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				num_meal;
	long long		time_last_meal;
	pthread_t		tid;
	struct s_simul	*simul;
}				t_philo;

typedef struct s_fork
{
	pthread_mutex_t	mutex_fork;
	pthread_mutex_t	mutex_status;
	int				status;
}				t_fork;

typedef struct s_simul
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_must_eat;
	enum e_bool		flag_finish;
	long long		time_launch;
	t_philo			*arr_philo;
	// pthread_mutex_t	*arr_forks;
	struct s_fork	*arr_forks;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_time_meal;
	pthread_mutex_t	mutex_num_meal;
	pthread_mutex_t	mutex_flag_finish;
}				t_simul;

/*
main.c
*/
void		*case_one_func(void *arg);
int			case_one_philo(t_simul *simul);
/*
libft
*/
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *nptr);
/*
utils.c
*/
int			ft_p_error(char *str);
long long	get_time(void);
void		mutex_printf(t_simul *simul, char *str, int id);
void		pthread_usleep(t_simul *simul, long long time);
t_bool		check_flag(t_simul *simul);
/*
init1.c
*/
void		take_argv_to_simul(int argc, char **argv, t_simul *simul);
t_bool		check_argv(t_simul *simul, int argc);
void		init_simul(t_simul *simul);
void		init_philo(t_simul *simul);
/*
init2.c
*/
t_bool		init_mutex_forks(t_simul *simul);
t_bool		init_mutex_others(t_simul *simul);
/*
thread1.c
*/
t_bool		create_thread(t_simul *simul);
void		*pthread_func(void *arg);
/*
thread2.c
*/
void		grab_fork(t_philo *philo);
void		dining(t_philo *philo);
void		put_down_fork(t_philo *philo);
void		sleeping(t_philo *philo);
/*
monitor.c
*/
t_bool		check_death(t_simul *simul, int i);
void		cnt_fin(t_simul *simul, int i, int *flag_cnt);
t_bool		check_fin(t_simul *simul, int flag_cnt);
void		monitoring(t_simul *simul);
/*
terminate.c
*/
void		terminate_thread(t_simul *simul);
void		terminate_mutex(t_simul *simul);
void		free_all(t_simul *simul);
/*
error.c
*/
int			free_p_err(t_simul *simul, char *str);
int			free_all_p_err(t_simul *simul, char *str);
int			free_all_terminate_p_err(t_simul *simul, char *str);

#endif