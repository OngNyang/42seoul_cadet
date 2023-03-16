#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "./get_next_line.h"
# include <stdio.h>

// #define NULL 0

int	cnt_a_b;
int	cnt_b_a;

typedef enum	e_bool
{
	FALSE = 0,
	TRUE = 1
}				t_bool;

typedef struct	s_node
{
	int		data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_deque
{
	t_node	*front;
	t_node	*rear;
}				t_deque;

/*
error
*/
void	p_error(char *message);
/*
stack.c
*/
t_node	*new_node(int data);
t_deque	*new_deque(void);
int		deque_size(t_deque *deque);

/*
stack_pop_push.c
*/
void	push_f(t_deque *deque, t_node *node);
void	push_r(t_deque *deque, t_node *node);
t_node	*pop_f(t_deque *deque);
t_node	*pop_r(t_deque *deque);

/*
operation.c
*/
t_bool	push(t_deque *deque_from, t_deque *deque_to);
t_bool	swap(t_deque	*deque);
t_bool	rotate(t_deque *deque);
t_bool	rev_rotate(t_deque *deque);

/*
argv_check.c
*/
void	check_argv(char **argv);
t_bool	check_digit(char *str);
t_bool	zero_exception(char *str);
t_bool	check_limit_value(char *str);

/*
argv_check_utils.c
*/
t_bool	is_sign(char c);
t_bool	cmp_argv(char *str1, char *str2);

/*
sort.c
*/
t_bool	is_sorted(t_deque *stack);
int		choose_pivot(t_deque *stack, int size);
void	a_to_b(int size, t_deque *stack_a, t_deque *stack_b);
void	b_to_a(int size, t_deque *stack_a, t_deque *stack_b);
void	push_swap_quick_sort(t_deque *stack_a, t_deque *stack_b);
void	sort_3(t_deque *stack);
void	sort_5(t_deque *stack_a, t_deque *stack_b);
void	print_stack(t_deque *s_a, t_deque *s_b);

/*sort_utils.c*/
t_bool	is_sorted(t_deque *stack);
int		find_min_num(t_deque *stack);
int		find_max_num(t_deque *stack);
int		choose_pivot(t_deque *stack, int size);
void	bubbleSort(long long *arr, int n);

/*
commands.c
*/
void	sa_sb(t_deque	*stack, char c);
void	ss(t_deque *stack_a, t_deque *stack_b);
void	pa_pb(t_deque *deque_from, t_deque *deque_to, char c);
void	ra_rb(t_deque *stack, char c);
void	rr(t_deque *stack_a, t_deque *stack_b);
void	rra_rb(t_deque *stack, char c);
void	rrr(t_deque *stack_a, t_deque *stack_b);

#endif