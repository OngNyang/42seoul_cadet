/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:37:32 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/24 11:36:24 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->simul->arr_forks[philo->l_fork].mutex_fork));
	philo->simul->arr_forks[philo->l_fork].status_fork = 1;
	mutex_printf(philo->simul, "has taken a fork", philo->id);
	pthread_mutex_lock(&(philo->simul->arr_forks[philo->r_fork].mutex_fork));
	philo->simul->arr_forks[philo->r_fork].status_fork = 1;
	mutex_printf(philo->simul, "has taken a fork", philo->id);
}

void	dining(t_philo *philo)
{
	mutex_printf(philo->simul, "is eating", philo->id);
	pthread_mutex_lock(&(philo->simul->mutex_time_meal));
	philo->time_last_meal = get_time();
	pthread_mutex_unlock(&(philo->simul->mutex_time_meal));
	pthread_mutex_lock(&(philo->simul->mutex_num_meal));
	philo->num_meal++;
	pthread_mutex_unlock(&(philo->simul->mutex_num_meal));
	pthread_usleep(philo->simul, philo->simul->time_eat);
}

void	put_down_fork(t_philo *philo)
{
	philo->simul->arr_forks[philo->l_fork].status_fork = 0;
	pthread_mutex_unlock(&(philo->simul->arr_forks[philo->l_fork].mutex_fork));
	philo->simul->arr_forks[philo->r_fork].status_fork = 0;
	pthread_mutex_unlock(&(philo->simul->arr_forks[philo->r_fork].mutex_fork));
}

void	sleeping(t_philo *philo)
{
	mutex_printf(philo->simul, "is sleeping", philo->id);
	pthread_usleep(philo->simul, philo->simul->time_sleep);
	mutex_printf(philo->simul, "is thinking", philo->id);
	usleep(100);
}
