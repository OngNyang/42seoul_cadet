/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:39:26 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/19 18:07:19 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	check_death(t_simul *simul, int i)
{
	long long	time_diff;

	pthread_mutex_lock(&(simul->mutex_time_meal));
	time_diff = get_time() - simul->arr_philo[i].time_last_meal;
	pthread_mutex_unlock(&(simul->mutex_time_meal));
	if (time_diff >= simul->time_die)
	{
		mutex_printf(simul, "died", simul->arr_philo[i].id);
		pthread_mutex_lock(&(simul->mutex_flag_finish));
		simul->flag_finish = TRUE;
		pthread_mutex_unlock(&(simul->mutex_flag_finish));
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
