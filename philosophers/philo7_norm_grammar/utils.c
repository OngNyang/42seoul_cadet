/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:25:44 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/19 12:53:08 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_p_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

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
