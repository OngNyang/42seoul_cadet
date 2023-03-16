#include "push_swap.h"

void	b_to_a(int size, t_deque *stack_a, t_deque *stack_b, t_node *node_a, t_node *node_b);

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

void	a_to_b(int size, t_deque *stack_a, t_deque *stack_b, t_node *node_a, t_node *node_b)
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
	if (size == 2)
	{
		if (node_a->data > node_a->next->data)
			sa_sb(stack_a , 'a');
		return ;
	}
	if (stack_a->rear == NULL)
		return ;
	pivot = stack_a->rear->data;
	i = 0;
	while (i < size)
	{
		if (node_a->next->data > pivot)
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
			// node_a = stack_a->front;
		}
		i++;
	}
	i = 0;
	while (i < ra_num)
	{
		rra_rb(stack_a, 'a');
		// rev_rotate(stack_a);				//rra
		i++;
	}
	(void)node_b;
//왜 rra로 다시 되감아햐함?
	// if (is_sorted(stack_a) == FALSE)
	a_to_b(ra_num, stack_a, stack_b, node_a, node_b);
	// if (is_sorted(stack_b) == FALSE)
	// b_to_a(pb_num, stack_a, stack_b, node_a, node_b);
}

void	b_to_a(int size, t_deque *stack_a, t_deque *stack_b, t_node *node_a, t_node *node_b)
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
		if (node_b->data < pivot)
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
		a_to_b(pa_num, stack_a, stack_b, node_a, node_b);
	// if (is_sorted(stack_b) == FALSE)
		b_to_a(rb_num, stack_a, stack_b, node_a, node_b);
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
	t_node	*node_a;
	t_node	*node_b;

	node_a = stack_a->front;
	node_b = stack_b->front;
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
		a_to_b(size, stack_a, stack_b, node_a, node_b);


	// sort_3(stack_a);
	// (void)stack_b;
	// sort_5(stack_a, stack_b);
	//a_to_b(size, stack_a, stack_b);
	// b_to_a(size, stack_a, stack_b);
}
