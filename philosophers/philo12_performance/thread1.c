/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:33:12 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/19 17:31:19 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	slow_start(t_philo *philo)
{
	if (philo->id % 2 == 1)
		usleep(100);
}

void	*pthread_func(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	slow_start(philo);
	while (1)
	{
		if (check_flag(philo->simul) == TRUE)
			break ;
		grab_fork(philo);
		dining(philo);
		put_down_fork(philo);
		// if (check_flag_fin(philo) == TRUE)
		if (check_flag(philo->simul) == TRUE)
			break ;
		sleeping(philo);
	}
	return (NULL);
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
		if (pthread_create(&(simul->arr_philo[i].tid), \
		NULL, pthread_func, (void *)&(simul->arr_philo[i])))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
