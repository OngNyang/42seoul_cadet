#include "push_swap.h"

void	b_to_a(int size, t_deque *stack_a, t_deque *stack_b);

void	print_stack(t_deque *s_a, t_deque *s_b)
{
	t_node	*a;
	t_node	*b;

	a = s_a->front;
	b = s_b->front;
	printf("\nstack_a : ");
	while (a)
	{
		printf("-%d-", a->data);
		a = a->next;
	}
	printf("\nstack_b : ");
	while (b)
	{
		printf("-%d-", b->data);
		b = b->next;
	}
	printf("\n");
}


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

void	ft_swap(long long *arr, int idx, int l_idx)
{
	int	tmp;

	tmp = arr[idx];
	arr[idx] = arr[l_idx];
	arr[l_idx] = tmp;
}

void	sort_arr(long long *arr, int cnt)
{
	int idx;
	int	jdx;
	int least;
	int	least_idx;

	idx = 0;
	while (idx < cnt - 1)
	{
		least = arr[idx];
		least_idx = idx;
		jdx = idx + 1;
		while (jdx < cnt)
		{
			if (least > arr[jdx])
			{
				least = arr[jdx];
				least_idx = jdx;
			}
			jdx++;
		}
		ft_swap(arr, idx, least_idx);
		idx++;
	}
}

int	choose_pivot(t_deque *stack, int size)
{
	t_node	*temp;
	long long	*arr;
	int			idx;
	int			result;

	temp = stack->front;
	arr = (long long *)malloc(sizeof(long long) * size);
	idx = 0;
	while (idx < size)
	{
		arr[idx++] = temp->data;
		temp = temp->next;
	}
	idx = 0;
	sort_arr(arr, size);
	result = arr[size / 2];
	free(arr);
	return (result);
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

//--------------------------------------------------
	cnt_a_b++;
	printf("-----a_to_b--| %d |---\n", cnt_a_b);
//--------------------------------------------------
	if (size == 1 || size == 0)
	{
		printf("size 0 1\n");
		print_stack(stack_a, stack_b);
		return ;
	}
	if (size == 2)
	{
		if (stack_a->front->data > stack_a->front->next->data)
			sa_sb(stack_a, 'a');
		printf("size2\n");
		print_stack(stack_a, stack_b);
		return ;
	}
	ra_num = 0;
	pb_num = 0;
	pivot = choose_pivot(stack_a, size);
	i = 0;
	while (i < size)
	{
		if (stack_a->front->data > pivot)
		{
			ra_rb(stack_a, 'a');				//ra
			ra_num++;
		}
		else
		{
			pa_pb(stack_a, stack_b, 'b');		//pb
			pb_num++;
		}
		i++;
	}
	i = 0;
	while (i < ra_num)
	{
		rra_rb(stack_a, 'a');		//rra
		i++;
	}
	print_stack(stack_a, stack_b);
	a_to_b(ra_num, stack_a, stack_b);
	b_to_a(pb_num, stack_a, stack_b);
}

void	b_to_a(int size, t_deque *stack_a, t_deque *stack_b)
{
	int	pivot;
	int	i;
	int	rb_num;
	int	pa_num;

	cnt_b_a++;
	printf("-----b_to_a--| %d |---\n", cnt_b_a);
	if (size == 1)
	{
		pa_pb(stack_b, stack_a, 'a');			//pa
		// pa_num -= 1;
		printf("size 1");
		print_stack(stack_a, stack_b);
		return ;
	}
	rb_num = 0;
	pa_num = 0;
	pivot = choose_pivot(stack_b, size);
	i = 0;
	while (i < size)
	{
		if (stack_b->front->data < pivot)
		{
			rotate(stack_b);				//rb
			rb_num++;
		}
		else
		{
			push(stack_b, stack_a);			//pa_num
			pa_num++;
		}
		i++;
	}
	i = 0;
	while (i < rb_num)
	{
		rev_rotate(stack_b);				//rrb
		i++;
	}
	print_stack(stack_a, stack_b);
	a_to_b(pa_num, stack_a, stack_b);
	b_to_a(rb_num, stack_a, stack_b);
}

int	find_max_num(t_deque *stack)
{
	int	res;
	t_node	*node;

	node = stack->front;
	res = node->data;
	while (node)
	{
		if (node->data > res)
			res = node->data;
		node = node->next;
	}
	return (res);
}

int	find_min_num(t_deque *stack)
{
	int	res;
	t_node	*node;

	node = stack->front;
	res = node->data;
	while (node)
	{
		if (node->data < res)
			res = node->data;
		node = node->next;
	}
	return (res);
}

void	sort_3(t_deque *stack)
{
	int	min_num;
	int	i;
	int stack_size;

	stack_size = deque_size(stack);
	if (is_sorted(stack) == TRUE)
		return ;
	min_num = find_min_num(stack);
	i = 0;
	while (i < stack_size)
	{
		if (stack->front->data == min_num)
			break ;
		ra_rb(stack, 'a');
		i++;
	}
	ra_rb(stack, 'a');
	if (stack->front->data > stack->front->next->data)
		sa_sb(stack, 'a');
	rra_rb(stack, 'a');
}


void	sort_5(t_deque *stack_a, t_deque *stack_b)
{
	int	max_num;
	int	min_num;
	int	i;
	int	stack_size;

	if (is_sorted(stack_a) == TRUE)
		return ;
	max_num = find_max_num(stack_a);
	min_num = find_min_num(stack_a);
	stack_size = deque_size(stack_a);
	i = 0;
	while (i < stack_size)
	{
		if (stack_a->front->data == max_num || stack_a->front->data == min_num)
			pa_pb(stack_a, stack_b, 'b');
		else
			ra_rb(stack_a, 'a');
		i++;
	}
	sort_3(stack_a);
	pa_pb(stack_b, stack_a, 'a');
	pa_pb(stack_b, stack_a, 'a');
	if (stack_a->front->data < stack_a->front->next->data)
		sa_sb(stack_a, 'a');
	ra_rb(stack_a, 'a');
}



void	push_swap_quick_sort(t_deque *stack_a, t_deque *stack_b)
{
	int	size;

	size = deque_size(stack_a);
	if (size == 1)
		return ;
	if (size == 2)
	{
		if (stack_a->front->data > stack_a->front->next->data)
			sa_sb(stack_a, 'a');
		return ;
	}
	else if (size == 3)
		sort_3(stack_a);
	else if (size <= 5)
		sort_5(stack_a, stack_b);
	else
		a_to_b(size, stack_a, stack_b);


	// sort_3(stack_a);
	// (void)stack_b;
	// sort_5(stack_a, stack_b);
	//a_to_b(size, stack_a, stack_b);
	// b_to_a(size, stack_a, stack_b);
}