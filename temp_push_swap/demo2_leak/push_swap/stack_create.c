/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:53:46 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/18 20:53:48 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int data)
{
	t_node	*node = (t_node*)malloc(sizeof(t_node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_deque	*new_deque(void)
{
	t_deque	*deque = (t_deque*)malloc(sizeof(t_deque));
	deque->front = NULL;
	deque->rear = NULL;
	return (deque);
}

int	deque_size(t_deque *deque)
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = deque->front;
	while (node != NULL)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}