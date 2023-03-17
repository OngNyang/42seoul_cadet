#include "push_swap.h"

void	sort_2(t_deque *stack, char c)
{
	if (stack->front->data > stack->front->next->data)
		sa_sb(stack, c);
	else
		return ;
}

// void	sort_3(t_deque *stack)
// {
// 	int	min_num;
// 	int	i;
// 	int stack_size;

// 	stack_size = deque_size(stack);
// 	if (is_sorted(stack) == TRUE)
// 		return ;
// 	min_num = find_min_num(stack);
// 	i = 0;
// 	while (i < stack_size)
// 	{
// 		if (stack->front->data == min_num)
// 			break ;
// 		ra_rb(stack, 'a');
// 		i++;
// 	}
// 	ra_rb(stack, 'a');
// 	if (stack->front->data > stack->front->next->data)
// 		sa_sb(stack, 'a');
// 	rra_rb(stack, 'a');
// }


void	sort_3_srr(t_deque *stack, char c)
{
	sa_sb(stack, c);
	rra_rb(stack, c);
}


void	sort_3(t_deque *stack, char c)
{
	int	min_num_idx;

	if (is_sorted(stack, 3) == TRUE)
		return ;
	min_num_idx = find_min_num_idx(stack, 3);
	if (min_num_idx == 0)
	{
		rra_rb(stack, c);
		sa_sb(stack, c);
	}
	else if (min_num_idx == 1)
	{
		if (stack->front->data > stack->front->next->next->data)
			ra_rb(stack, c);
		else
			sa_sb(stack, c);
	}
	else if (min_num_idx == 2)
	{
		if (stack->front->data < stack->front->next->data)
			rra_rb(stack, c);
		else
			sort_3_srr(stack, c);
	}
}

void	sort_5(t_deque *stack_a, t_deque *stack_b, char c)
{
	int	max_num;
	int	min_num;
	int	i;
	int	stack_size;

	if (is_sorted(stack_a, 5) == TRUE)
		return ;
	max_num = find_max_num(stack_a, 5);
	min_num = find_min_num(stack_a, 5);
	stack_size = deque_size(stack_a);
	i = 0;
	// while (i < stack_size)
	while (i < 5)
	{
		if (stack_a->front->data == max_num || stack_a->front->data == min_num)
			pa_pb(stack_a, stack_b, 'b');
		else
			ra_rb(stack_a, 'a');
		i++;
	}
	sort_3(stack_a, c);
	pa_pb(stack_b, stack_a, 'a');
	pa_pb(stack_b, stack_a, 'a');
	if (stack_a->front->data < stack_a->front->next->data)
		sa_sb(stack_a, 'a');
	ra_rb(stack_a, 'a');
}

// void	push_swap_quick_sort(t_deque *stack_a, t_deque *stack_b)
// {
// 	int	size;

// 	size = deque_size(stack_a);
// 	if (size == 1)
// 		return ;
// 	if (size == 2)
// 	{
// 		if (stack_a->front->data > stack_a->front->next->data)
// 			sa_sb(stack_a, 'a');
// 		return ;
// 	}
// 	else if (size == 3)
// 		sort_3(stack_a, 'a');
// 	else if (size <= 5)
// 		sort_5(stack_a, stack_b, 'a');
// 	else
// 		// a_to_b(size, stack_a, stack_b);
// 		divide(size, stack_a, stack_b);
// }


// void	print_stack(t_deque *s_a, t_deque *s_b)
// {
// 	t_node	*a;
// 	t_node	*b;

// 	a = s_a->front;
// 	b = s_b->front;
// 	printf("\nstack_a : ");
// 	while (a)
// 	{
// 		printf("-%d-", a->data);
// 		a = a->next;
// 	}
// 	printf("\nstack_b : ");
// 	while (b)
// 	{
// 		printf("-%d-", b->data);
// 		b = b->next;
// 	}
// 	printf("\n");
// }







/*
중위값을 피벗으로
*/

// void	a_to_b(int size, t_deque *stack_a, t_deque *stack_b)
// {
// 	int	pivot;
// 	int	i;
// 	int	ra_num;
// 	int	pb_num;

// //--------------------------------------------------
// 	cnt_a_b++;
// 	printf("-----a_to_b--| %d |---\n", cnt_a_b);
// //--------------------------------------------------
// 	if (size == 1 || size == 0)
// 	{
// 		printf("size 0 1\n");
// 		print_stack(stack_a, stack_b);
// 		return ;
// 	}
// 	if (size == 2)
// 	{
// 		if (stack_a->front->data > stack_a->front->next->data)
// 			sa_sb(stack_a, 'a');
// 		printf("size2\n");
// 		print_stack(stack_a, stack_b);
// 		return ;
// 	}
// 	ra_num = 0;
// 	pb_num = 0;
// 	pivot = choose_pivot(stack_a, size);
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (stack_a->front->data > pivot)
// 		{
// 			ra_rb(stack_a, 'a');				//ra
// 			ra_num++;
// 		}
// 		else
// 		{
// 			pa_pb(stack_a, stack_b, 'b');		//pb
// 			pb_num++;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < ra_num)
// 	{
// 		rra_rb(stack_a, 'a');		//rra
// 		i++;
// 	}
// 	print_stack(stack_a, stack_b);
// 	a_to_b(ra_num, stack_a, stack_b);
// 	b_to_a(pb_num, stack_a, stack_b);
// }

// void	b_to_a(int size, t_deque *stack_a, t_deque *stack_b)
// {
// 	int	pivot;
// 	int	i;
// 	int	rb_num;
// 	int	pa_num;

// 	cnt_b_a++;
// 	printf("-----b_to_a--| %d |---\n", cnt_b_a);
// 	if (size == 1)
// 	{
// 		pa_pb(stack_b, stack_a, 'a');			//pa
// 		// pa_num -= 1;
// 		printf("size 1");
// 		print_stack(stack_a, stack_b);
// 		return ;
// 	}
// 	rb_num = 0;
// 	pa_num = 0;
// 	pivot = choose_pivot(stack_b, size);
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (stack_b->front->data < pivot)
// 		{
// 			ra_rb(stack_b, 'b');				//rb
// 			rb_num++;
// 		}
// 		else
// 		{
// 			pa_pb(stack_b, stack_a, 'a');			//pa_num
// 			pa_num++;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < rb_num)
// 	{
// 		rra_rb(stack_b, 'b');				//rrb
// 		i++;
// 	}
// 	print_stack(stack_a, stack_b);
// 	a_to_b(pa_num, stack_a, stack_b);
// 	b_to_a(rb_num, stack_a, stack_b);
// }

