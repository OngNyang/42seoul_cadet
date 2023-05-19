/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:45:09 by hyejeong          #+#    #+#             */
/*   Updated: 2023/05/19 15:05:21 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_p_err(t_simul *simul, char *str)
{
	free(simul);
	return (ft_p_error(str));
}

int	free_all_p_err(t_simul *simul, char *str)
{
	free_all(simul);
	return (ft_p_error(str));
}

int	free_all_terminate_p_err(t_simul *simul, char *str)
{
	terminate_mutex(simul);
	free_all(simul);
	return (ft_p_error(str));
}
