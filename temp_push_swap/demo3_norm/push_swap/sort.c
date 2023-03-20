/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:53:43 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/18 20:53:45 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_deque *stack, char c)
{
	if (stack->front->data > stack->front->next->data)
		sa_sb(stack, c);
	else
		return ;
}

void	sort_3_srr(t_deque *stack, char c)
{
	sa_sb(stack, c);
	rra_rb(stack, c);
}

void	sort_3(t_deque *stack, char c)
{
	int	min_num_idx;

	if (is_sorted(stack, 3) == TRUE)
		return ;
	min_num_idx = find_min_num_idx(stack, 3);
	if (min_num_idx == 0)
	{
		rra_rb(stack, c);
		sa_sb(stack, c);
	}
	else if (min_num_idx == 1)
	{
		if (stack->front->data > stack->front->next->next->data)
			ra_rb(stack, c);
		else
			sa_sb(stack, c);
	}
	else if (min_num_idx == 2)
	{
		if (stack->front->data < stack->front->next->data)
			rra_rb(stack, c);
		else
			sort_3_srr(stack, c);
	}
}

void	sort_5(t_deque *stack_a, t_deque *stack_b, char c)
{
	int	max_num;
	int	min_num;
	int	i;

	if (is_sorted(stack_a, 5) == TRUE)
		return ;
	max_num = find_max_num(stack_a, 5);
	min_num = find_min_num(stack_a, 5);
	i = 0;
	while (i < 5)
	{
		if (stack_a->front->data == max_num || stack_a->front->data == min_num)
			pa_pb(stack_a, stack_b, 'b');
		else
			ra_rb(stack_a, 'a');
		i++;
	}
	sort_3(stack_a, c);
	pa_pb(stack_b, stack_a, 'a');
	pa_pb(stack_b, stack_a, 'a');
	if (stack_a->front->data < stack_a->front->next->data)
		sa_sb(stack_a, 'a');
	ra_rb(stack_a, 'a');
}

void	push_swap(t_deque *stack_a, t_deque *stack_b, int size)
{
	if (is_sorted(stack_a, size) == TRUE)
		exit(0);
	else
		divide(size, stack_a, stack_b);
}
