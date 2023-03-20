/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:53:05 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/18 20:53:09 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	push(t_deque *deque_from, t_deque *deque_to)
{
	if (deque_from->front == NULL)
		return (FALSE);
	push_f(deque_to, pop_f(deque_from));
	return (TRUE);
}

t_bool	swap(t_deque	*deque)
{
	int	temp;

	if (deque->front == deque->rear)
		return (FALSE);
	temp = deque->front->data;
	deque->front->data = deque->front->next->data;
	deque->front->next->data = temp;
	return (TRUE);
}

t_bool	rotate(t_deque *deque)
{
	if (deque->front == NULL)
		return (FALSE);
	push_r(deque, pop_f(deque));
	return (TRUE);
}

t_bool	rev_rotate(t_deque *deque)
{
	if (deque->rear == NULL)
		return (FALSE);
	push_f(deque, pop_r(deque));
	return (TRUE);
}
