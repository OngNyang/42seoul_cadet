/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:25:44 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/20 01:53:44 by hyejeong         ###   ########.fr       */
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
	t_bool	temp_flag;

	pthread_mutex_lock(&(simul->mutex_flag_finish));
	temp_flag = simul->flag_finish;
	pthread_mutex_unlock(&(simul->mutex_flag_finish));
	if (temp_flag == TRUE)
		return ;
	else
	{
		pthread_mutex_lock(&(simul->mutex_print));
		printf("%lld %d %s\n", get_time() - simul->time_launch, id, str);
		pthread_mutex_unlock(&(simul->mutex_print));
	}
}

void	pthread_usleep(t_simul *simul, long long time)
{
	long long	end_time;
	long long	now;
	t_bool		temp_flag;

	now = get_time();
	end_time = now + time;
	while (now <= end_time)
	{
		pthread_mutex_lock(&(simul->mutex_flag_finish));
		temp_flag = simul->flag_finish;
		pthread_mutex_unlock(&(simul->mutex_flag_finish));
		if (temp_flag == TRUE)
			return ;
		usleep(100);
		now = get_time();
	}
}

t_bool	check_flag(t_simul *simul)
{
	pthread_mutex_lock(&(simul->mutex_flag_finish));
	if (simul->flag_finish == TRUE)
	{
		pthread_mutex_unlock(&(simul->mutex_flag_finish));
		return (TRUE);
	}
	pthread_mutex_unlock(&(simul->mutex_flag_finish));
	return (FALSE);
}
