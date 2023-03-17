#include "push_swap.h"

int	choose_pivot(t_deque *stack, int size)
{
	int		i;
	t_node	*node;

	i = 0;
	while (i < size / 2)
	{
		node = node->next;
		i++;
	}
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
	pivot = choose_pivot(stack_a, size);
	i = 0;
	while (i < size)
	{
		if (stack_a->front->data > pivot)
		{
			rotate(stack_a);				//ra
			ra_num++;
		}
		else
		{
			push(stack_a, stack_b);			//pb
			pb_num++;
		}
		i++;
	}
	i = 0;
	while (i < ra_num)
		rev_rotate(stack_a);				//rra
	a_to_b(ra_num, stack_a, stack_b);
	b_to_a(pb_num, stack_a, stack_b);
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
		push(stack_b, stack_a);				//pa
		return ;
	}
	pivot = choose_pivot(stack_b, size);
	i = 0;
	while (i < size)
	{
		if (stack_b->front->data > pivot)
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
	a_to_b(pa_num, stack_a, stack_b);
	b_to_a(rb_num, stack_a, stack_b);
}

void	push_swap_quick_sort(t_deque *stack_a, t_deque *stack_b)
{
	int	size;

	size = deque_size(stack_a);
	a_to_b(size, stack_a, stack_b);
}