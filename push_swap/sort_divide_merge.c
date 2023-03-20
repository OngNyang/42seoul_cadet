/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_divide_merge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:53:33 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/18 20:53:34 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	sort_stack_a(int size, t_deque *stack_a, t_deque *stack_b, int pivot)
{
	int		i;
	t_num	numset;

	numset.r_num = 0;
	numset.p_num = 0;
	i = 0;
	while (i++ < size)
	{
		if (stack_a->front->data > pivot)
		{
			ra_rb(stack_a, 'a');
			numset.r_num++;
		}
		else
		{
			pa_pb(stack_a, stack_b, 'b');
			numset.p_num++;
		}
	}
	if (deque_size(stack_a) == numset.r_num)
		return (numset);
	i = 0;
	while (i++ < numset.r_num)
		rra_rb(stack_a, 'a');
	return (numset);
}

void	divide(int size, t_deque *stack_a, t_deque *stack_b)
{
	int		pivot;
	t_num	numset;

	if (size == 1 || size == 0)
		return ;
	else if (size == 2)
	{
		sort_2(stack_a, 'a');
		return ;
	}
	else if (size == 3 && deque_size(stack_a) == 3)
	{
		sort_3(stack_a, 'a');
		return ;
	}
	else if (size == 5 && deque_size(stack_a) == 5)
	{
		sort_5(stack_a, stack_b, 'a');
		return ;
	}
	pivot = choose_pivot(stack_a, size);
	numset = sort_stack_a(size, stack_a, stack_b, pivot);
	divide(numset.r_num, stack_a, stack_b);
	combine(numset.p_num, stack_a, stack_b);
}

t_num	sort_stack_b(int size, t_deque *stack_a, t_deque *stack_b, int pivot)
{
	int		i;
	t_num	numset;

	numset.r_num = 0;
	numset.p_num = 0;
	i = 0;
	while (i < size)
	{
		if (stack_b->front->data < pivot)
		{
			ra_rb(stack_b, 'b');
			numset.r_num++;
		}
		else
		{
			pa_pb(stack_b, stack_a, 'a');
			numset.p_num++;
		}
		i++;
	}
	i = 0;
	while (i++ < numset.r_num)
		rra_rb(stack_b, 'b');
	return (numset);
}

void	combine(int size, t_deque *stack_a, t_deque *stack_b)
{
	int		pivot;
	t_num	numset;

	if (size == 1)
		pa_pb(stack_b, stack_a, 'a');
	else
	{
		pivot = choose_pivot(stack_b, size);
		numset = sort_stack_b(size, stack_a, stack_b, pivot);
		divide(numset.p_num, stack_a, stack_b);
		combine(numset.r_num, stack_a, stack_b);
	}
}
