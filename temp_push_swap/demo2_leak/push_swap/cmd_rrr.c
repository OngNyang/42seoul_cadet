/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:53:17 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/18 20:53:19 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_deque *stack, char c)
{
	rotate(stack);
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_deque *stack_a, t_deque *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	rra_rb(t_deque *stack, char c)
{
	rev_rotate(stack);
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_deque *stack_a, t_deque *stack_b)
{
	rev_rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}