/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:53:39 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/18 20:53:42 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_num(t_deque *stack, int n)
{
	int	res;
	t_node	*node;
	int	i;

	i = 0;
	node = stack->front;
	res = node->data;
	while (node && i < n)
	{
		if (node->data > res)
			res = node->data;
		node = node->next;
		i++;
	}
	return (res);
}

int	find_min_num(t_deque *stack, int n)
{
	int	res;
	t_node	*node;
	int	i;

	i = 0;
	node = stack->front;
	res = node->data;
	while (node && i < n)
	{
		if (node->data < res)
			res = node->data;
		node = node->next;
		i++;
	}
	return (res);
}

int	find_min_num_idx(t_deque *stack, int n)
{
	int	res;
	t_node	*node;
	int	i;

	i = 0;
	node = stack->front;
	res = node->data;
	while (node && i < n)
	{
		if (node->data < res)
			res = node->data;
		node = node->next;
		i++;
	}
	i = 0;
	node = stack->front;
	while (i < n)
	{
		if (node->data == res)
			break ;
		node= node->next;
		i++;
	}
	return (i);
}