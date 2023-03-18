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
	return (i);
}

t_bool	is_sorted(t_deque *stack, int n)
{
	t_node	*node;
	int	i;

	i = 0;
	node = stack->front->next;
	while (node && i < n)
	{
		if (node->data < node->prev->data)
			return (FALSE);
		node = node->next;
		i++;
	}
	return (TRUE);
}

void	bubbleSort(long long *arr, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < n - 1) {
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	choose_pivot(t_deque *stack, int size)
{
	t_node		*temp;
	long long	*arr;
	int			i;
	int			res;

	temp = stack->front;
	arr = (long long *)malloc(sizeof(long long) * size);
	i = 0;
	while (i < size)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	bubbleSort(arr, size);
	res = arr[size / 2];
	free(arr);
	return (res);
}