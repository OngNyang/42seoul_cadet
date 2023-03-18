/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:53:55 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/18 21:05:41 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "./get_next_line.h"

//---------------------------------
# include <stdio.h>
//---------------------------------

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

typedef struct	s_num
{
	int	r_num;
	int	p_num;
}				t_num;

/*
argv_check_utils.c
*/
t_bool	is_sign(char c);
t_bool	cmp_argv(char *str1, char *str2);

/*
argv_check.c
*/
t_bool	check_digit(char *str);
t_bool	check_limit_value(char *str);
t_bool	zero_exception(char *str);
void	check_argv(char **argv);

/*
cmd_operation.c
*/
t_bool	push(t_deque *deque_from, t_deque *deque_to);
t_bool	swap(t_deque	*deque);
t_bool	rotate(t_deque *deque);
t_bool	rev_rotate(t_deque *deque);

/*
cmd_ps.c
*/
void	sa_sb(t_deque	*stack, char c);
void	ss(t_deque *stack_a, t_deque *stack_b);
void	pa_pb(t_deque *deque_from, t_deque *deque_to, char c);


/*
cmd_rrr.c
*/
void	ra_rb(t_deque *stack, char c);
void	rr(t_deque *stack_a, t_deque *stack_b);
void	rra_rb(t_deque *stack, char c);
void	rrr(t_deque *stack_a, t_deque *stack_b);

/*
error
*/
void	p_error(char *message);
void	free_node(t_deque *stack);

/*
sort_divide_merge.c
*/
t_num	sort_stack_a(int size, t_deque *stack_a, t_deque *stack_b, int pivot);
void	divide(int size, t_deque *stack_a, t_deque *stack_b);
t_num	sort_stack_b(int size, t_deque *stack_a, t_deque *stack_b, int pivot);
void	combine(int size, t_deque *stack_a, t_deque *stack_b);


/*
sort.c
*/
void	sort_2(t_deque *stack, char c);
void	sort_3_srr(t_deque *stack, char c);
void	sort_3(t_deque *stack, char c);
void	sort_5(t_deque *stack_a, t_deque *stack_b, char c);
void	push_swap(t_deque *stack_a, t_deque *stack_b, int size);
// void	push_swap_quick_sort(t_deque *stack_a, t_deque *stack_b);

/*sort_utils2.c*/
int		find_min_num_idx(t_deque *stack, int n);
int		find_min_num(t_deque *stack, int n);
int		find_max_num(t_deque *stack, int n);

/*
sort_utils.c
*/
t_bool	is_sorted(t_deque *stack, int n);
void	bubbleSort(long long *arr, int n);
int		choose_pivot(t_deque *stack, int size);

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



#endif