#include "push_swap.h"

t_bool	is_sorted(t_deque *stack)
{
	t_node	*node;

	node = stack->front->next;
	while (node)
	{
		if (node->data < node->prev->data)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}

int	choose_pivot(t_deque *stack, int size)
{
	int		i;
	t_node	*node;

	node = stack->front;
	i = 0;
	while (i < size / 2)
	{
		node = node->next;
		i++;
	}
	printf("%d\n", node->data);
	return (node->data);
}
/*
중위값을 피벗으로
*/

void	a_to_b(int size, t_deque *stack_a, t_deque *stack_b)
{
	int	pivot;
	int	i;
	int	ra_num;
	int	pb_num;

	ra_num = 0;
	pb_num = 0;
	if (size == 1)
		return ;
	// pivot = choose_pivot(stack_a, size);
	if (stack_a->rear == NULL)
		return ;
	pivot = stack_a->rear->data;
	i = 0;
	while (i < size)
	{
		if (stack_a->front->data > pivot)
		{
			ra_rb(stack_a, 'a');
			// rotate(stack_a);				//ra
			ra_num++;
		}
		else
		{
			pa_pb(stack_a, stack_b, 'b');
			// push(stack_a, stack_b);			//pb
			pb_num++;
		}
		i++;
	}
	// i = 0;
	// while (i < ra_num)
	// {
	// 	rra_rb(stack_a, 'a');
	// 	// rev_rotate(stack_a);				//rra
	// 	i++;
	// }
//왜 rra로 다시 되감아햐함?
	// if (is_sorted(stack_a) == FALSE)
		a_to_b(ra_num, stack_a, stack_b);
	// if (is_sorted(stack_b) == FALSE)
		//b_to_a(pb_num, stack_a, stack_b);
}

void	b_to_a(int size, t_deque *stack_a, t_deque *stack_b)
{
	int	pivot;
	int	i;
	int	rb_num;
	int	pa_num;

	rb_num = 0;
	pa_num = 0;
	if (size == 1)
	{
		pa_pb(stack_b, stack_a, 'a');
		// push(stack_b, stack_a);				//pa
		return ;
	}
	// pivot = choose_pivot(stack_b, size);
	if (stack_b->rear == NULL)
		return ;
	pivot = stack_b->rear->data;
	i = 0;
	while (i < size)
	{
		if (stack_b->front->data > pivot)
		{
			ra_rb(stack_b, 'b');
			// rotate(stack_b);				//rb
			rb_num++;
		}
		else
		{
			pa_pb(stack_b, stack_a, 'a');
			// push(stack_b, stack_a);			//pa
			pa_num++;
		}
		i++;
	}
	i = 0;
	while (i < rb_num)
	{
		rra_rb(stack_b, 'b');
		// rev_rotate(stack_b);				//rrb
		i++;
	}
	// if (is_sorted(stack_a) == FALSE)
		a_to_b(pa_num, stack_a, stack_b);
	// if (is_sorted(stack_b) == FALSE)
		b_to_a(rb_num, stack_a, stack_b);
}

void	push_swap_quick_sort(t_deque *stack_a, t_deque *stack_b)
{
	int	size;

	size = deque_size(stack_a);
	a_to_b(size, stack_a, stack_b);
	// b_to_a(size, stack_a, stack_b);
}

// void	ft_swap(long long *arr, int idx, int l_idx)
// {
// 	int	tmp;

// 	tmp = arr[idx];
// 	arr[idx] = arr[l_idx];
// 	arr[l_idx] = tmp;
// }

// void	sort_arr(long long *arr, int cnt)
// {
// 	int idx;
// 	int	jdx;
// 	int least;
// 	int	least_idx;

// 	idx = 0;
// 	while (idx < cnt - 1)
// 	{
// 		least = arr[idx];
// 		least_idx = idx;
// 		jdx = idx + 1;
// 		while (jdx < cnt)
// 		{
// 			if (least > arr[jdx])
// 			{
// 				least = arr[jdx];
// 				least_idx = jdx;
// 			}
// 			jdx++;
// 		}
// 		ft_swap(arr, idx, least_idx);
// 		idx++;
// 	}
// }
