#include "push_swap.h"

void	sa_sb(t_deque	*stack, char c)
{
	swap(stack);
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_deque *stack_a, t_deque *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}

void	pa_pb(t_deque *deque_from, t_deque *deque_to, char c)
{
	push(deque_from, deque_to);
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}

