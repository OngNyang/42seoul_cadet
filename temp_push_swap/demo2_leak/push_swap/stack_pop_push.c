/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:53:49 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/18 20:53:51 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_f(t_deque *deque, t_node *node)
{
	if (deque->front == NULL)	//비어있으면 1개만 등록
	{
		deque->front = node;
		deque->rear = node;
	}
	else		//
	{
		node->next = deque->front;
		deque->front->prev = node;
		deque->front = node;
	}
}

void	push_r(t_deque *deque, t_node *node)
{
	if (deque->rear == NULL)	//비어있으면 1개만 등록
	{
		deque->front = node;
		deque->rear = node;
	}
	else		//
	{
		node->prev = deque->rear;
		deque->rear->next = node;
		deque->rear = node;
	}
}

t_node	*pop_f(t_deque *deque)
{
	t_node	*node;

	if (deque->front == NULL)
		return (NULL);
	node = deque->front;
	deque->front = deque->front->next;
	if (deque->front == NULL)		//마지막 한개였으면
		deque->rear = NULL;
	else
		deque->front->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*pop_r(t_deque *deque)
{
	t_node	*node;

	if (deque->rear == NULL)
		return (NULL);
	node = deque->rear;
	deque->rear = deque->rear->prev;
	if (deque->rear == NULL)		//마지막 한개였으면
		deque->front = NULL;
	else
		deque->rear->next = NULL;
	node->prev = NULL;
	return (node);
}
