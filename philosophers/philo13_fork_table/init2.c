/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:29:57 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/20 00:28:24 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_mutex_forks(t_simul *simul)
{
	int	i;

	simul->arr_forks = (t_fork *)malloc(sizeof(t_fork) \
	* simul->num_philo);
	i = 0;
	while (i < simul->num_philo)
	{
		if (pthread_mutex_init(&(simul->arr_forks[i].mutex_fork), NULL) != 0)
			return (FALSE);
		if (pthread_mutex_init(&(simul->arr_forks[i].mutex_status), NULL) != 0)
			return (FALSE);
		i++;
		simul->arr_forks[i].status = 0;
	}
	return (TRUE);
}

t_bool	init_mutex_others(t_simul *simul)
{
	// if (pthread_mutex_init(&(simul->mutex_flag_dead), NULL) != 0)
	// 	return (FALSE);
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
