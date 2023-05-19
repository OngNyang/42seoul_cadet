/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:23:41 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/19 12:52:26 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_simul	*simul;

	simul = (t_simul *)malloc(sizeof(t_simul) * 1);
	if (!(argc == 5 || argc == 6))
		return (ft_p_error("Error: wrong argument\n"));
	take_argv_to_simul(argc, argv, simul);
	if ((check_argv(simul, argc)) == FALSE)
		return (ft_p_error("Error: wrong argument\n"));
	init_simul(simul);
	init_philo(simul);
	if (init_mutex_forks(simul) == FALSE)
		return (ft_p_error("Error: pthread_mutex_init\n"));
	if (init_mutex_others(simul) == FALSE)
		return (ft_p_error("Error: pthread_mutex_init\n"));
	if (create_thread(simul) == FALSE)
		return (ft_p_error("Error: pthread_create\n"));
	monitoring(simul);
	terminate_thread(simul);
	terminate_mutex(simul);
	free_all(simul);
	return (0);
}
