/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:41:35 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/19 18:07:24 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	// pthread_mutex_destroy(&(simul->mutex_flag_dead));
	pthread_mutex_destroy(&(simul->mutex_flag_finish));
	pthread_mutex_destroy(&(simul->mutex_num_meal));
	pthread_mutex_destroy(&(simul->mutex_time_meal));
}

void	free_all(t_simul *simul)
{
	free(simul->arr_forks);
	free(simul->arr_philo);
	free(simul);
}
