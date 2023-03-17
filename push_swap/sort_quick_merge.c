#include "push_swap.h"




void	a_to_b(int size, t_deque *stack_a, t_deque *stack_b)
{
	int	pivot;
	int	i;
	int	ra_num;
	int	pb_num;

//--------------------------------------------------
	cnt_a_b++;
	printf("\n-----a_to_b--| %d |---\n", cnt_a_b);
	printf("size : %d\n", size);
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
	printf("\npivot_a :%d\n", pivot);
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
	while (i++ < ra_num)
		rra_rb(stack_a, 'a');		//rra
	print_stack(stack_a, stack_b);
	printf("a_to_b(%d)\n", ra_num);
	printf("b_to_a(%d)\n", pb_num);
	a_to_b(ra_num, stack_a, stack_b);
	b_to_a(pb_num, stack_a, stack_b);
}

void	b_to_a(int size, t_deque *stack_a, t_deque *stack_b)
{
	int	pivot;
	int	i;
	int	rb_num;
	int	pa_num;

//------------------------------------------------
	cnt_b_a++;
	printf("\n-----b_to_a--| %d |---\n", cnt_b_a);
	printf("size : %d\n", size);
//------------------------------------------------
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
	printf("\npivot_b :%d\n", pivot);
	i = 0;
	while (i < size)
	{
		if (stack_b->front->data < pivot)
		{
			ra_rb(stack_b, 'b');				//rb
			rb_num++;
		}
		else
		{
			pa_pb(stack_b, stack_a, 'a');			//pa_num
			pa_num++;
		}
		i++;
	}
	i = 0;
	while (i++ < rb_num)
		rra_rb(stack_b, 'b');				//rrb
	print_stack(stack_a, stack_b);
	printf("a_to_b(%d)\n", pa_num);
	printf("b_to_a(%d)\n", rb_num);
	a_to_b(pa_num, stack_a, stack_b);
	b_to_a(rb_num, stack_a, stack_b);
}
