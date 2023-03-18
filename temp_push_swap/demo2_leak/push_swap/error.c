/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:53:20 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/18 21:04:50 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_error(char *message)
{
	ft_putstr_fd("Error\n", 1);
	(void)message;
	// ft_putstr_fd(message, 1);
	// ft_putchar_fd('\n', 1);
	exit(1);
}

void	free_node(t_deque *stack)
{
	t_node	*node;
	t_node	*next_node;

	node = stack->front;
	while (node)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	free(stack);
}