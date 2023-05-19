/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:26:21 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/19 12:27:37 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_argv_to_simul(int argc, char **argv, t_simul *simul)
{
	simul->num_philo = ft_atoi(argv[NUM_OF_PHILO]);
	simul->time_die = ft_atoi(argv[TIME_TO_DIE]);
	simul->time_eat = ft_atoi(argv[TIME_TO_EAT]);
	simul->time_sleep = ft_atoi(argv[TIME_TO_SLEEP]);
	if (argc == 5)
		simul->num_must_eat = 0;
	else if (argc == 6)
		simul->num_must_eat = ft_atoi(argv[NUM_MUST_EAT]);
}

t_bool	check_argv(t_simul *simul, int argc)
{
	if (simul->num_philo < 1)
		return (FALSE);
	if (simul->num_must_eat == 0 && argc == 6)
		return (FALSE);
	return (TRUE);
}

void	init_simul(t_simul *simul)
{
	simul->flag_dead = FALSE;
	simul->flag_finish = FALSE;
	simul->time_launch = 0;
}

void	init_philo(t_simul *simul)
{
	int	i;

	simul->arr_philo = (t_philo *)malloc(sizeof(t_philo) * simul->num_philo);
	i = 0;
	while (i < simul->num_philo)
	{
		simul->arr_philo[i].id = i + 1;
		simul->arr_philo[i].l_fork = i;
		simul->arr_philo[i].r_fork = i + 1;
		if (i == simul->num_philo - 1)
			simul->arr_philo[i].r_fork = 0;
		simul->arr_philo[i].time_last_meal = 0;
		simul->arr_philo[i].num_meal = 0;
		simul->arr_philo[i].simul = simul;
		i++;
	}
}