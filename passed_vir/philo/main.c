/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:23:41 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/24 11:40:24 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	*case_one_func(void *arg)
{
	t_simul		*simul;
	long long	time_launch;
	long long	end_time;
	long long	now;

	simul = (t_simul *)arg;
	time_launch = get_time();
	now = get_time();
	end_time = time_launch + simul->time_die;
	pthread_mutex_lock(&(simul->arr_forks[0].mutex_fork));
	simul->arr_forks[0].status_fork = 1;
	printf("0 1 has taken fork\n");
	while (now <= end_time)
	{
		usleep(10);
		now = get_time();
	}
	pthread_mutex_unlock(&(simul->arr_forks[0].mutex_fork));
	simul->arr_forks[0].status_fork = 0;
	printf("%lld 1 died\n", get_time() - time_launch);
	return (NULL);
}

int	case_one_philo(t_simul *simul)
{
	pthread_t	tid;

	simul->arr_forks = (t_fork *)malloc(sizeof(t_fork) * 1);
	if (pthread_mutex_init(&(simul->arr_forks[0].mutex_fork), NULL) != 0)
	{
		free(simul->arr_forks);
		return (free_p_err(simul, "Error: mutex_init\n"));
	}
	simul->arr_forks[0].status_fork = 0;
	if (pthread_create(&(tid), NULL, case_one_func, (void *)(simul)))
		return (free_p_err(simul, "Error: pthread_create\n"));
	pthread_join(tid, NULL);
	pthread_mutex_destroy(&(simul->arr_forks[0].mutex_fork));
	free(simul->arr_forks);
	free(simul);
	return (0);
}

int	main(int argc, char **argv)
{
	t_simul	*simul;

	simul = (t_simul *)malloc(sizeof(t_simul) * 1);
	if (!(argc == 5 || argc == 6))
		return (free_p_err(simul, "Error: wrong argument\n"));
	take_argv_to_simul(argc, argv, simul);
	if ((check_argv(simul, argc)) == FALSE)
		return (free_p_err(simul, "Error: wrong argument\n"));
	if (simul->num_philo == 1)
		return (case_one_philo(simul));
	else
	{
		init_simul(simul);
		init_philo(simul);
		if (init_mutex_forks(simul) == FALSE)
			return (free_all_p_err(simul, "Error: pthread_mutex_init\n"));
		if (init_mutex_others(simul) == FALSE)
			return (free_all_p_err(simul, "Error: pthread_mutex_init\n"));
		if (create_thread(simul) == FALSE)
			free_all_terminate_p_err(simul, "Error: pthread_create\n");
		monitoring(simul);
		terminate_thread(simul);
		terminate_mutex(simul);
		free_all(simul);
	}
}
