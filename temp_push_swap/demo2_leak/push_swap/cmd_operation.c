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
	/*
	주소 바꾸고, prev, next 바꾸기
	*/
	if (deque_from->front == NULL)
		return (FALSE);
	push_f(deque_to, pop_f(deque_from));
	return (TRUE);
}

t_bool	swap(t_deque	*deque)
{
	/*
	최상단 2대 바꾸기.
	data값만 바꾸면 되는거 아님?
	*/
	int	temp;

	if (deque->front == deque->rear)	//원소의 갯수가 0,1개일때만 가능한 상황
		return (FALSE);
	temp = deque->front->data;
	deque->front->data = deque->front->next->data;
	deque->front->next->data = temp;
	return (TRUE);
}

t_bool	rotate(t_deque *deque)
{
	/*
	최상단을 최하단으로 내리면 되는거 아닌가.
	*/
	if (deque->front == NULL)	//원소의 갯수가 0개일때
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