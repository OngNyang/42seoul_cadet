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